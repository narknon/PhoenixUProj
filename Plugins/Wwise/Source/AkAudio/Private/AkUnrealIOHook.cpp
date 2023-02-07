/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "AkUnrealIOHook.h"

#include "AkAudioDevice.h"
#include "AkMediaAsset.h"
#include "AkUnrealHelper.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Async/AsyncFileHandle.h"
#include "HAL/FileManager.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Misc/Paths.h"

#if WITH_EDITOR
#include "Async/Async.h"
#endif

FCriticalSection FAkUnrealIOHook::MediaMapCriticalSection;
TMap<uint32, TArray<TWeakObjectPtr<UAkMediaAsset>>> FAkUnrealIOHook::StreamingMediaMap;
TMap<FString, TArray<TWeakObjectPtr<UAkExternalMediaAsset>>> FAkUnrealIOHook::ExternalMediaMap;

struct AkFileCustomParam
{
	virtual ~AkFileCustomParam() {}
	virtual AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) = 0;

	static void SetupAkFileDesc(AkFileDesc& fileDesc, AkFileCustomParam* customParam)
	{
		fileDesc.pCustomParam = customParam;
		fileDesc.uCustomParamSize = sizeof(AkFileCustomParam);
	}

	static AkFileCustomParam* GetFileCustomParam(const AkFileDesc& fileDesc)
	{
		if (fileDesc.uCustomParamSize == sizeof(AkFileCustomParam))
		{
			return reinterpret_cast<AkFileCustomParam*>(fileDesc.pCustomParam);
		}

		return nullptr;
	}
};

struct AkReadAssetCustomParam : public AkFileCustomParam
{
public:
	AkReadAssetCustomParam(TWeakObjectPtr<UAkMediaAsset> MediaAsset)
	{
		this->MediaAsset = TWeakObjectPtr<UAkMediaAsset>(MediaAsset.Get());
		BulkData = const_cast<FByteBulkData*>(&(MediaAsset->GetStreamedChunk()->Data));
	}

	virtual ~AkReadAssetCustomParam()
	{
		for (auto& ioRequest : IORequests)
		{
			if (ioRequest)
			{
				ioRequest->WaitCompletion();
				delete ioRequest;
			}
		}
	}

	AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) override
	{
		auto AkTransferInfo = io_transferInfo;

		for (auto& ioRequest : IORequests)
		{
			if (ioRequest && ioRequest->PollCompletion())
			{
				ioRequest->WaitCompletion();
				delete ioRequest;
				ioRequest = nullptr;
			}
		}

		IORequests.Remove(nullptr);

		BulkDataRequestCompletedCallback AsyncFileCallBack = [AkTransferInfo](bool bWasCancelled, ReadRequestArgumentType* ReadRequest) mutable
		{
			if (AkTransferInfo.pCallback)
			{
				AkTransferInfo.pCallback(&AkTransferInfo, AK_Success);
			}
		};

		if (MediaAsset.IsValid())
		{
			BulkDataIORequest* PendingReadRequest = BulkData->CreateStreamingRequest(AkTransferInfo.uFilePosition, AkTransferInfo.uRequestedSize, AIOP_High, &AsyncFileCallBack, (uint8*)AkTransferInfo.pBuffer);
			if (PendingReadRequest)
			{
				IORequests.Add(PendingReadRequest);
			}
			return AK_Success;
		}
		else
		{
			return AK_Fail;
		}
	}

public:
	FByteBulkData* BulkData = nullptr;
	TWeakObjectPtr<UAkMediaAsset> MediaAsset;
	TArray<BulkDataIORequest*, TInlineAllocator<8>> IORequests;
};

struct AkEditorReadCustomParam : AkFileCustomParam
{
public:
#if UE_4_25_OR_LATER
#if USE_NEW_BULKDATA
	AkEditorReadCustomParam(FByteBulkData& BulkData)
#else
	AkEditorReadCustomParam(const FByteBulkData& BulkData)
#endif
#else
	AkEditorReadCustomParam(const FByteBulkData& BulkData)
#endif
	{
		RawData = BulkData.LockReadOnly();
		BulkData.Unlock();
	}

	~AkEditorReadCustomParam()
	{
		RawData = nullptr;
	}

	AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) override
	{
		if (io_transferInfo.pCallback)
		{
			FMemory::Memcpy(io_transferInfo.pBuffer, reinterpret_cast<const uint8*>(RawData) + io_transferInfo.uFilePosition, io_transferInfo.uRequestedSize);
			io_transferInfo.pCallback(&io_transferInfo, AK_Success);
		}

		return AK_Success;
	}

public:
	const void* RawData = nullptr;
};

struct AkWriteFileCustomParam : AkFileCustomParam
{
private:
	IFileHandle* FileHandle;

public:
	AkWriteFileCustomParam(IFileHandle* handle)
	: FileHandle(handle)
	{}

	virtual ~AkWriteFileCustomParam()
	{
		if (FileHandle)
		{
			delete FileHandle;
		}
	}

	virtual AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) override
	{
		FileHandle->Seek(io_transferInfo.uFilePosition);

		if (FileHandle->Write((uint8*)io_transferInfo.pBuffer, io_transferInfo.uBufferSize))
		{
			if (io_transferInfo.pCallback)
			{
				io_transferInfo.pCallback(&io_transferInfo, AK_Success);
			}

			return AK_Success;
		}

		return AK_Fail;
	}
};

FAkUnrealIOHook::FAkUnrealIOHook()
{
	assetRegistryModule = &FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	localizedPackagePath = AkUnrealHelper::GetLocalizedAssetPackagePath();
	mediaPackagePath = FPaths::Combine(AkUnrealHelper::GetBaseAssetPackagePath(), AkUnrealHelper::MediaFolderName);
}

FAkUnrealIOHook::~FAkUnrealIOHook()
{
	if (AK::StreamMgr::GetFileLocationResolver() == this)
	{
		AK::StreamMgr::SetFileLocationResolver(nullptr);
	}

	AK::StreamMgr::DestroyDevice(m_deviceID);
}

bool FAkUnrealIOHook::Init(const AkDeviceSettings& in_deviceSettings)
{
	if (in_deviceSettings.uSchedulerTypeFlags != AK_SCHEDULER_DEFERRED_LINED_UP)
	{
		AKASSERT(!"CAkDefaultIOHookDeferred I/O hook only works with AK_SCHEDULER_DEFERRED_LINED_UP devices");
		return false;
	}

	// If the Stream Manager's File Location Resolver was not set yet, set this object as the 
	// File Location Resolver (this I/O hook is also able to resolve file location).
	if (!AK::StreamMgr::GetFileLocationResolver())
	{
		AK::StreamMgr::SetFileLocationResolver(this);
	}

	// Create a device in the Stream Manager, specifying this as the hook.
	m_deviceID = AK::StreamMgr::CreateDevice(in_deviceSettings, this);
	return m_deviceID != AK_INVALID_DEVICE_ID;
}

AKRESULT FAkUnrealIOHook::Open(
	const AkOSChar*			in_pszFileName,
	AkOpenMode				in_eOpenMode,
	AkFileSystemFlags*		in_pFlags,
	bool&					io_bSyncOpen,
	AkFileDesc&			out_fileDesc
)
{
	CleanFileDescriptor(out_fileDesc);

	if (!io_bSyncOpen)
	{
		// Our open is blocking, wait for the IO thread to call us back
		return AK_Success;
	}

	if (in_eOpenMode == AK_OpenModeRead && in_pFlags->uCompanyID == AKCOMPANYID_AUDIOKINETIC_EXTERNAL)
	{
		auto assetName = FPaths::GetBaseFilename(in_pszFileName);
		auto externalSourceAsset = GetExternalSourceAsset(assetName);
		if (externalSourceAsset == nullptr)
		{
			return AK_Fail;
		}
		auto result = DoAssetOpen(externalSourceAsset, out_fileDesc);
		externalSourceAsset->RemoveFromRoot();
		RemoveExternalMedia(externalSourceAsset);
		return result;
	}

	if (in_eOpenMode == AK_OpenModeWrite || in_eOpenMode == AK_OpenModeWriteOvrwr)
	{
		const auto TargetDirectory = FPaths::ProjectSavedDir() / TEXT("Wwise");
		static bool TargetDirectoryExists = false;
		if (!TargetDirectoryExists && !FPaths::DirectoryExists(TargetDirectory))
		{
			TargetDirectoryExists = true;
			if (!FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*TargetDirectory))
			{
				UE_LOG(LogAkAudio, Error, TEXT("Cannot create writable directory at %s"), *TargetDirectory);
				return AK_NotImplemented;
			}
		}
		auto fullPath = FPaths::Combine(TargetDirectory, FString(in_pszFileName));
		if (auto FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*fullPath))
		{
			AkFileCustomParam::SetupAkFileDesc(out_fileDesc, new AkWriteFileCustomParam(FileHandle));
			return AK_Success;
		}
		else
		{
			UE_LOG(LogAkAudio, Error, TEXT("Cannot open file %s for write."), *fullPath);
		}
	}

	return AK_NotImplemented;
}

AKRESULT FAkUnrealIOHook::Open(
	AkFileID				in_fileID,          // File ID.
	AkOpenMode				in_eOpenMode,       // Open mode.
	AkFileSystemFlags*		in_pFlags,			// Special flags. Can pass NULL.
	bool&					io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
	AkFileDesc&			out_fileDesc        // Returned file descriptor.
)
{
	CleanFileDescriptor(out_fileDesc);
	if (!io_bSyncOpen)
	{
		// Our open is blocking, wait for the IO thread to call us back
		return AK_Success;
	}

	if (in_eOpenMode != AK_OpenModeRead)
	{
		return AK_NotImplemented;
	}

	return DoAssetOpen(GetStreamingAsset((uint32)in_fileID), out_fileDesc);
}

TWeakObjectPtr<UAkMediaAsset> FAkUnrealIOHook::GetStreamingAsset(const uint32 assetID)
{
	FScopeLock Lock(&MediaMapCriticalSection);
	if (!StreamingMediaMap.Contains(assetID))
	{
		UE_LOG(LogAkAudio, Error, TEXT("Could not find streaming file ID %d in the Media Map. Is the UAkMediaAsset properly loaded?"), assetID);
		return {};
	}
	auto Media = StreamingMediaMap.FindRef(assetID);
	if (Media.Num() == 0) 
	{
		UE_LOG(LogAkAudio, Error, TEXT("No media associated with file ID %d currently loaded."), assetID);
		return {};
	}

	for (auto Entry : Media)
	{
		if (Entry.IsValid())
		{
			return Entry;
		}
	}

	return {};
}

TWeakObjectPtr<UAkExternalMediaAsset> FAkUnrealIOHook::GetExternalSourceAsset(const FString &assetName)
{	
	FScopeLock Lock(&MediaMapCriticalSection);
	if (!ExternalMediaMap.Contains(assetName))
	{
		UE_LOG(LogAkAudio, Error, TEXT("Could not find external source file ID %s in the Media Map. Is the UAkExternalMediaAsset properly loaded?"), *assetName);
		return {};
	}
	auto Media = ExternalMediaMap.FindRef(assetName);
	if (Media.Num() == 0)
	{
		UE_LOG(LogAkAudio, Error, TEXT("Media associated with file name %s currently loaded."), *assetName);
		return {};
	}

	for (auto Entry : Media)
	{
		if (Entry.IsValid())
		{
			return Entry;
		}
	}

	return {};
}

AKRESULT FAkUnrealIOHook::DoAssetOpen(TWeakObjectPtr<UAkMediaAsset> MediaAsset, AkFileDesc& OutFileDesc)
{
	if (!MediaAsset.IsValid(true, true) || !MediaAsset->IsValidLowLevelFast())
	{
		return AK_Fail;
	}

	auto StreamedChunk = MediaAsset->GetStreamedChunk();
	if (!StreamedChunk)
	{
		return AK_Fail;
	}

	OutFileDesc.iFileSize = StreamedChunk->Data.GetBulkDataSize();

#if WITH_EDITOR
#if UE_5_0_OR_LATER
	if (StreamedChunk->Data.GetBulkDataOffsetInFile() == -1 || StreamedChunk->Data.GetPackagePath().IsEmpty())
#else
	if (StreamedChunk->Data.GetBulkDataOffsetInFile() == -1 || StreamedChunk->Data.GetFilename().Len() == 0)
#endif
	{
		auto customParam = new AkEditorReadCustomParam(StreamedChunk->Data);
		AkFileCustomParam::SetupAkFileDesc(OutFileDesc, customParam);
		return AK_Success;
	}
#endif

	auto CustomParam = new AkReadAssetCustomParam(MediaAsset);
	AkFileCustomParam::SetupAkFileDesc(OutFileDesc, CustomParam);
	return AK_Success;
}

AKRESULT FAkUnrealIOHook::Read(
	AkFileDesc &			in_fileDesc,
	const AkIoHeuristics &	in_heuristics,
	AkAsyncIOTransferInfo & io_transferInfo
)
{
	auto fileCustomParam = AkFileCustomParam::GetFileCustomParam(in_fileDesc);
	if (fileCustomParam)
	{
		return fileCustomParam->DoWork(io_transferInfo);
	}
	
	return AK_Fail;
}

AKRESULT FAkUnrealIOHook::Write(
	AkFileDesc &			in_fileDesc,
	const AkIoHeuristics&	in_heuristics,
	AkAsyncIOTransferInfo& io_transferInfo
)
{
	auto fileCustomParam = AkFileCustomParam::GetFileCustomParam(in_fileDesc);
	if (fileCustomParam)
	{
		return fileCustomParam->DoWork(io_transferInfo);
	}

	return AK_Fail;
}

void FAkUnrealIOHook::Cancel(
	AkFileDesc &			in_fileDesc,
	AkAsyncIOTransferInfo & io_transferInfo,
	bool & io_bCancelAllTransfersForThisFile
)
{
}

AKRESULT FAkUnrealIOHook::Close(AkFileDesc& in_fileDesc)
{
	auto fileCustomParam = AkFileCustomParam::GetFileCustomParam(in_fileDesc);
	if (fileCustomParam)
	{
		delete fileCustomParam;
	}

	AkFileCustomParam::SetupAkFileDesc(in_fileDesc, nullptr);
	return AK_Success;
}

// Returns the block size for the file or its storage device. 
AkUInt32 FAkUnrealIOHook::GetBlockSize(AkFileDesc& in_fileDesc)
{
	return 1;
}

// Returns a description for the streaming device above this low-level hook.
void FAkUnrealIOHook::GetDeviceDesc(AkDeviceDesc& 
#if !defined(AK_OPTIMIZED)
	out_deviceDesc
#endif
)
{
#if !defined(AK_OPTIMIZED)
	// Deferred scheduler.
	out_deviceDesc.deviceID = m_deviceID;
	out_deviceDesc.bCanRead = true;
	out_deviceDesc.bCanWrite = true;
	AK_CHAR_TO_UTF16(out_deviceDesc.szDeviceName, "UnrealIODevice", AK_MONITOR_DEVICENAME_MAXLENGTH);
	out_deviceDesc.szDeviceName[AK_MONITOR_DEVICENAME_MAXLENGTH - 1] = '\0';
	out_deviceDesc.uStringSize = (AkUInt32)AKPLATFORM::AkUtf16StrLen(out_deviceDesc.szDeviceName) + 1;
#endif
}

// Returns custom profiling data: 1 if file opens are asynchronous, 0 otherwise.
AkUInt32 FAkUnrealIOHook::GetDeviceData()
{
	return 1;
}

void FAkUnrealIOHook::CleanFileDescriptor(AkFileDesc& out_fileDesc)
{
	out_fileDesc.uSector = 0;
	out_fileDesc.deviceID = m_deviceID;

	auto fileCustomParam = AkFileCustomParam::GetFileCustomParam(out_fileDesc);
	if (fileCustomParam)
	{
		delete fileCustomParam;
	}

	AkFileCustomParam::SetupAkFileDesc(out_fileDesc, nullptr);

	out_fileDesc.iFileSize = 0;
}

void FAkUnrealIOHook::AddStreamingMedia(UAkMediaAsset* MediaToAdd)
{
	if (MediaToAdd)
	{
		auto MediaPtr = TWeakObjectPtr<UAkMediaAsset>(MediaToAdd);
		FScopeLock Lock(&MediaMapCriticalSection);
		if (!StreamingMediaMap.Contains(MediaToAdd->Id))
		{
			StreamingMediaMap.Add(MediaToAdd->Id, TArray<TWeakObjectPtr<UAkMediaAsset>>({ MediaPtr }));
		}
		else
		{
			StreamingMediaMap.Find(MediaToAdd->Id)->Push(MediaPtr);
		}
	}
}

void FAkUnrealIOHook::RemoveStreamingMedia(UAkMediaAsset* MediaToRemove)
{
	if (MediaToRemove)
	{
		FScopeLock Lock(&MediaMapCriticalSection);
		auto Media = StreamingMediaMap.FindRef(MediaToRemove->Id);
		Media.Remove(TWeakObjectPtr<UAkMediaAsset>(MediaToRemove));
		if (Media.Num()==0)
		{
			StreamingMediaMap.Remove(MediaToRemove->Id);
		}
	}
}

void FAkUnrealIOHook::AddExternalMedia(UAkExternalMediaAsset* MediaToAdd)
{
	if (MediaToAdd)
	{
		MediaToAdd->NumStreamingHandles.Increment();
		{
			auto MediaPtr = TWeakObjectPtr<UAkExternalMediaAsset>(MediaToAdd);
			FScopeLock Lock(&MediaMapCriticalSection);
			if (!ExternalMediaMap.Contains(MediaToAdd->GetName()))
			{
				ExternalMediaMap.Add(MediaToAdd->GetName(), TArray<TWeakObjectPtr<UAkExternalMediaAsset>>({ MediaPtr }));
			}
			else
			{
				ExternalMediaMap.Find(MediaToAdd->GetName())->Push(MediaPtr);
			}
		}
	}
}

void FAkUnrealIOHook::RemoveExternalMedia(TWeakObjectPtr<UAkExternalMediaAsset> MediaToRemove)
{
	if (MediaToRemove.IsValid() && MediaToRemove->NumStreamingHandles.Decrement() == 0)
	{
		FScopeLock Lock(&MediaMapCriticalSection);
		auto Media = ExternalMediaMap.FindRef(MediaToRemove->GetName());
		Media.Remove(TWeakObjectPtr<UAkExternalMediaAsset>(MediaToRemove));
		if (Media.Num()==0)
		{
			ExternalMediaMap.Remove(MediaToRemove->GetName());
		}
	}
}