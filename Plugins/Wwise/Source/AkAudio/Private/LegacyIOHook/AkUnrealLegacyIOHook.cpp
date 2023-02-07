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

//////////////////////////////////////////////////////////////////////
//
// AkUnrealLegacyIOHook.cpp
//
// Default deferred low level IO hook (AK::StreamMgr::IAkIOHookDeferred) 
// and file system (AK::StreamMgr::IAkFileLocationResolver) implementation 
// on Windows.
// 
// AK::StreamMgr::IAkFileLocationResolver: 
// Resolves file location using simple path concatenation logic 
// (implemented in ../Common/CAkFileLocationBase). It can be used as a 
// standalone Low-Level IO system, or as part of a multi device system. 
// In the latter case, you should manage multiple devices by implementing 
// AK::StreamMgr::IAkFileLocationResolver elsewhere (you may take a look 
// at class CAkDefaultLowLevelIODispatcher).
//
// AK::StreamMgr::IAkIOHookDeferred: 
// Uses platform API for I/O. Calls to ::ReadFile() and ::WriteFile() 
// do not block because files are opened with the FILE_FLAG_OVERLAPPED flag. 
// Transfer completion is handled by internal FileIOCompletionRoutine function,
// which then calls the AkAIOCallback.
// The AK::StreamMgr::IAkIOHookDeferred interface is meant to be used with
// AK_SCHEDULER_DEFERRED_LINED_UP streaming devices. 
//
// Init() creates a streaming device (by calling AK::StreamMgr::CreateDevice()).
// AkDeviceSettings::uSchedulerTypeFlags is set inside to AK_SCHEDULER_DEFERRED_LINED_UP.
// If there was no AK::StreamMgr::IAkFileLocationResolver previously registered 
// to the Stream Manager, this object registers itself as the File Location Resolver.
//
//
//////////////////////////////////////////////////////////////////////

#include "AkUnrealLegacyIOHook.h"
#include "AkAudioDevice.h"

// @todo:ak verify consistency of Wwise SDK alignment settings with unreal build settings on all platforms
//			Currently, Wwise SDK builds with the default alignment (8-bytes as per MSDN) with the VC toolchain.
//			Unreal builds with 4-byte alignment on the VC toolchain on both Win32 and Win64. 
//			This could (and currently does, on Win64) cause data corruption if the headers are not included with forced alignment directives as below.

#include "AkUnrealHelper.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Platforms/AkUEPlatform.h"

// Device info.
static constexpr auto DEFERRED_DEVICE_NAME = "UnrealIODeviceLegacy";

static constexpr uint32 ROUND_TO_BLOCK(uint32 ToBeRounded, uint32 BlockSize)
{
	return ((((ToBeRounded)+(BlockSize)-1) / BlockSize) * BlockSize);
}

AkLegacyFileCustomParam* AkLegacyFileCustomParam::GetFileCustomParam(const AkFileDesc& fileDesc)
{
	if (fileDesc.uCustomParamSize == sizeof(AkLegacyFileCustomParam))
	{
		return reinterpret_cast<AkLegacyFileCustomParam*>(fileDesc.pCustomParam);
	}

	return nullptr;
}

void AkLegacyFileCustomParam::SetupFileDesc(AkFileDesc& fileDesc, AkLegacyFileCustomParam* FileCustomParam)
{
	fileDesc.pCustomParam = FileCustomParam;
	fileDesc.uCustomParamSize = FileCustomParam ? (sizeof (AkLegacyFileCustomParam)) : -1;
}

struct AkLegacyReadFileCustomParam : AkLegacyFileCustomParam
{
private:
	IAsyncReadFileHandle* IORequestHandle;
	TArray<class IAsyncReadRequest*> ReadRequests;

public:
	AkLegacyReadFileCustomParam(IAsyncReadFileHandle* handle) : IORequestHandle(handle) {}

	virtual ~AkLegacyReadFileCustomParam()
	{
		for (auto& IORequest : ReadRequests)
		{
			if (IORequest)
			{
				IORequest->WaitCompletion();
				delete IORequest;
			}
		}

		delete IORequestHandle;
	}

	virtual AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) override
	{
		auto AkTransferInfo = io_transferInfo;

		for (auto& IORequest : ReadRequests)
		{
			if (IORequest && IORequest->PollCompletion())
			{
				IORequest->WaitCompletion();
				delete IORequest;
				IORequest = nullptr;
			}
		}

		ReadRequests.Remove(nullptr);

		uint8* TempMemory = nullptr;
#if PLATFORM_XBOXONE
		// Because of WG-38169, we can get unaligned pointers, which Xbox IO doesn't like. We need to allocate an aligned temp buffer to avoid crashes.
		if (((uint64)AkTransferInfo.pBuffer) % AkLegacyFileCustomParamPolicy::GetBlockSize() != 0)
		{
			const uint32 RoundedSize = ROUND_TO_BLOCK(AkTransferInfo.uRequestedSize, AkLegacyFileCustomParamPolicy::GetBlockSize());
			TempMemory = (uint8*)FMemory::Malloc(RoundedSize, AkLegacyFileCustomParamPolicy::GetBlockSize());
		}
#endif

		FAsyncFileCallBack AsyncFileCallBack = [AkTransferInfo, TempMemory](bool bWasCancelled, IAsyncReadRequest* Req) mutable
		{
#if PLATFORM_XBOXONE
			if (TempMemory)
			{
				FMemory::Memcpy(AkTransferInfo.pBuffer, TempMemory, AkTransferInfo.uRequestedSize);
				FMemory::Free(TempMemory);
			}
#endif
			if (AkTransferInfo.pCallback)
				AkTransferInfo.pCallback(&AkTransferInfo, AK_Success);
		};
		auto PendingReadRequest = IORequestHandle->ReadRequest(AkTransferInfo.uFilePosition, AkTransferInfo.uRequestedSize, AIOP_High, &AsyncFileCallBack, TempMemory ? TempMemory : (uint8*)AkTransferInfo.pBuffer);
		if (PendingReadRequest)
			ReadRequests.Add(PendingReadRequest);
#if PLATFORM_XBOXONE
		else
			FMemory::Free(TempMemory);
#endif

		return AK_Success;
	}
};

struct AkLegacyWriteFileCustomParam : AkLegacyFileCustomParam
{
private:
	IFileHandle* FileHandle;

public:
	AkLegacyWriteFileCustomParam(IFileHandle* handle) : FileHandle(handle) {}

	virtual ~AkLegacyWriteFileCustomParam()
	{
		if (FileHandle)
			delete FileHandle;
	}

	virtual AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) override
	{
		FileHandle->Seek(io_transferInfo.uFilePosition);

		if (FileHandle->Write((uint8*)io_transferInfo.pBuffer, io_transferInfo.uBufferSize))
		{
			if (io_transferInfo.pCallback)
				io_transferInfo.pCallback(&io_transferInfo, AK_Success);

			return AK_Success;
		}

		return AK_Fail;
	}
};

// Initialization/termination. Init() registers this object as the one and 
// only File Location Resolver if none were registered before. Then 
// it creates a streaming device with scheduler type AK_SCHEDULER_DEFERRED_LINED_UP.
bool FAkUnrealLegacyIOHook::Init(const AkDeviceSettings& in_deviceSettings)
{
	if (in_deviceSettings.uSchedulerTypeFlags != AK_SCHEDULER_DEFERRED_LINED_UP)
	{
		AKASSERT(!"CAkDefaultIOHookDeferred I/O hook only works with AK_SCHEDULER_DEFERRED_LINED_UP devices");
		return false;
	}

	// If the Stream Manager's File Location Resolver was not set yet, set this object as the 
	// File Location Resolver (this I/O hook is also able to resolve file location).
	if (!AK::StreamMgr::GetFileLocationResolver())
		AK::StreamMgr::SetFileLocationResolver(this);

	// Create a device in the Stream Manager, specifying this as the hook.
	m_deviceID = AK::StreamMgr::CreateDevice(in_deviceSettings, this);

	m_szBasePath = FPaths::Combine(AkUnrealHelper::GetSoundBankDirectory(), FAkPlatform::GetPlatformBasePath());

	auto separator = FGenericPlatformMisc::GetDefaultPathSeparator();
	if (!m_szBasePath.EndsWith(separator))
	{
		m_szBasePath.Append(separator);
	}

	return m_deviceID != AK_INVALID_DEVICE_ID;
}

FAkUnrealLegacyIOHook::~FAkUnrealLegacyIOHook()
{
	if (AK::StreamMgr::GetFileLocationResolver() == this)
		AK::StreamMgr::SetFileLocationResolver(NULL);

	if (m_deviceID != AK_INVALID_DEVICE_ID)
	{
		AK::StreamMgr::DestroyDevice(m_deviceID);
		m_deviceID = AK_INVALID_DEVICE_ID;
	}
}

//
// IAkFileLocationAware implementation.
//-----------------------------------------------------------------------------

template<typename T>
AKRESULT FAkUnrealLegacyIOHook::PerformOpen( 
    T		        in_fileDescriptor,  // File ID or file Name.
    AkOpenMode      in_eOpenMode,       // Open mode.
    AkFileSystemFlags * in_pFlags,      // Special flags. Can pass NULL.
	bool &			io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
    AkFileDesc &    out_fileDesc        // Returned file descriptor.
    )
{
	CleanFileDescriptor(out_fileDesc);

	if (AK_OpenModeReadWrite == in_eOpenMode)
		return AK_NotImplemented;

	FString FilePath;
	if (GetFullFilePath(in_fileDescriptor, in_pFlags, in_eOpenMode, &FilePath) != AK_Success || FilePath.IsEmpty())
		return AK_Fail;

	if (AK_OpenModeRead == in_eOpenMode)
	{
		out_fileDesc.iFileSize = IFileManager::Get().FileSize(*FilePath);
		if (out_fileDesc.iFileSize > 0)
		{
			auto IORequestHandle = FPlatformFileManager::Get().GetPlatformFile().OpenAsyncRead(*FilePath);
			if (IORequestHandle)
			{
				io_bSyncOpen = true;
				AkLegacyFileCustomParam::SetupFileDesc(out_fileDesc, new AkLegacyReadFileCustomParam(IORequestHandle));
				return AK_Success;
			}
		}
	}
	else if (AK_OpenModeWrite == in_eOpenMode || AK_OpenModeWriteOvrwr == in_eOpenMode)
	{
		auto FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*FilePath);
		if (FileHandle)
		{
			io_bSyncOpen = true;
			AkLegacyFileCustomParam::SetupFileDesc(out_fileDesc, new AkLegacyWriteFileCustomParam(FileHandle));
			return AK_Success;
		}
	}

	return AK_Fail;
}

// Returns a file descriptor for a given file name (string).
AKRESULT FAkUnrealLegacyIOHook::Open( 
    const AkOSChar* in_pszFileName,     // File name.
    AkOpenMode      in_eOpenMode,       // Open mode.
    AkFileSystemFlags * in_pFlags,      // Special flags. Can pass NULL.
	bool &			io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
    AkFileDesc &    out_fileDesc        // Returned file descriptor.
    )
{
	FString FileName(in_pszFileName);
	return PerformOpen(FileName, in_eOpenMode, in_pFlags, io_bSyncOpen, out_fileDesc);
}

// Returns a file descriptor for a given file ID.
AKRESULT FAkUnrealLegacyIOHook::Open( 
    AkFileID        in_fileID,          // File ID.
    AkOpenMode      in_eOpenMode,       // Open mode.
    AkFileSystemFlags * in_pFlags,      // Special flags. Can pass NULL.
	bool &			io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
    AkFileDesc &    out_fileDesc        // Returned file descriptor.
    )
{
	return PerformOpen(in_fileID, in_eOpenMode, in_pFlags, io_bSyncOpen, out_fileDesc);
}


//
// IAkIOHookDeferred implementation.
//-----------------------------------------------------------------------------

// Reads data from a file (asynchronous overload).
AKRESULT FAkUnrealLegacyIOHook::Read(
	AkFileDesc &			in_fileDesc,        // File descriptor.
	const AkIoHeuristics & /*in_heuristics*/,	// Heuristics for this data transfer (not used in this implementation).
	AkAsyncIOTransferInfo & io_transferInfo		// Asynchronous data transfer info.
	)
{
	auto FileCustomParam = AkLegacyFileCustomParam::GetFileCustomParam(in_fileDesc);
	return FileCustomParam ? FileCustomParam->DoWork(io_transferInfo) : AK_Fail;
}

AKRESULT FAkUnrealLegacyIOHook::Write(
	AkFileDesc &			in_fileDesc,        // File descriptor.
	const AkIoHeuristics & /*in_heuristics*/,	// Heuristics for this data transfer (not used in this implementation).
	AkAsyncIOTransferInfo & io_transferInfo		// Platform-specific asynchronous IO operation info.
	)
{
	auto FileCustomParam = AkLegacyFileCustomParam::GetFileCustomParam(in_fileDesc);
	return FileCustomParam ? FileCustomParam->DoWork(io_transferInfo) : AK_Fail;
}


// Cancel transfer(s).
void FAkUnrealLegacyIOHook::Cancel(
	AkFileDesc &			in_fileDesc,		// File descriptor.
	AkAsyncIOTransferInfo & io_transferInfo,// Transfer info to cancel (this implementation only handles "cancel all").
	bool & io_bCancelAllTransfersForThisFile	// Flag indicating whether all transfers should be cancelled for this file (see notes in function description).
	)
{
}

// Close a file.
AKRESULT FAkUnrealLegacyIOHook::Close(
    AkFileDesc& in_fileDesc      // File descriptor.
    )
{
	auto FileCustomParam = AkLegacyFileCustomParam::GetFileCustomParam(in_fileDesc);
	if (FileCustomParam)
		delete FileCustomParam;

	AkLegacyFileCustomParam::SetupFileDesc(in_fileDesc, nullptr);
	return AK_Success;
}

void FAkUnrealLegacyIOHook::CleanFileDescriptor( AkFileDesc& out_fileDesc )
{
	out_fileDesc.uSector			= 0;
	out_fileDesc.deviceID			= m_deviceID;
	AkLegacyFileCustomParam::SetupFileDesc(out_fileDesc, nullptr);
	out_fileDesc.iFileSize			= 0;
}


// Returns the block size for the file or its storage device. 
AkUInt32 FAkUnrealLegacyIOHook::GetBlockSize(
    AkFileDesc &  in_fileDesc     // File descriptor.
    )
{
    return AkLegacyFileCustomParamPolicy::GetBlockSize(in_fileDesc);
}

// Returns a description for the streaming device above this low-level hook.
void FAkUnrealLegacyIOHook::GetDeviceDesc(
    AkDeviceDesc & 
#ifndef AK_OPTIMIZED
	out_deviceDesc      // Description of associated low-level I/O device.
#endif
    )
{
#ifndef AK_OPTIMIZED
	// Deferred scheduler.
	out_deviceDesc.deviceID       = m_deviceID;
	out_deviceDesc.bCanRead       = true;
	out_deviceDesc.bCanWrite      = true;
	AK_CHAR_TO_UTF16( out_deviceDesc.szDeviceName, DEFERRED_DEVICE_NAME, AK_MONITOR_DEVICENAME_MAXLENGTH );
	out_deviceDesc.szDeviceName[AK_MONITOR_DEVICENAME_MAXLENGTH - 1] = '\0';
	out_deviceDesc.uStringSize   = (AkUInt32)AKPLATFORM::AkUtf16StrLen( out_deviceDesc.szDeviceName ) + 1;
#endif
}

// Returns custom profiling data: 1 if file opens are asynchronous, 0 otherwise.
AkUInt32 FAkUnrealLegacyIOHook::GetDeviceData()
{
	return 0;
}

// Writes data to a file (asynchronous overload).
AKRESULT FAkUnrealLegacyIOHook::GetFullFilePath(
	const FString&		in_szFileName,		// File name.
	AkFileSystemFlags * in_pFlags,			// Special flags. Can be NULL.
	AkOpenMode			in_eOpenMode,		// File open mode (read, write, ...).
	FString*			out_szFullFilePath // Full file path.
	)
{
	if (in_szFileName.IsEmpty())
	{
		AKASSERT(!"Invalid file name");
		return AK_InvalidParameter;
	}

	// Prepend string path (basic file system logic).
	int32 uiPathSize = in_szFileName.Len();
	if (uiPathSize >= AK_MAX_PATH)
	{
		AKASSERT(!"Input string too large");
		return AK_InvalidParameter;
	}

	*out_szFullFilePath = m_szBasePath;

	if (in_pFlags && in_eOpenMode == AK_OpenModeRead)
	{
		// Add language directory name if needed.
		if (in_pFlags->bIsLanguageSpecific)
		{
			size_t uLanguageStrLen = AKPLATFORM::OsStrLen(AK::StreamMgr::GetCurrentLanguage());
			if (uLanguageStrLen > 0)
			{
				uiPathSize += (uLanguageStrLen + 1);
				if (uiPathSize >= AK_MAX_PATH)
				{
					AKASSERT(!"Path is too large");
					return AK_Fail;
				}
				FString CurrentLanguage(AK::StreamMgr::GetCurrentLanguage());
				*out_szFullFilePath = FPaths::Combine(**out_szFullFilePath, *CurrentLanguage);
				out_szFullFilePath->Append(FGenericPlatformMisc::GetDefaultPathSeparator());
			}
		}
	}

	// Append file title.
	uiPathSize += out_szFullFilePath->Len();
	if (uiPathSize >= AK_MAX_PATH)
	{
		AKASSERT(!"File name string too large");
		return AK_Fail;
	}

	out_szFullFilePath->Append(in_szFileName);
	return AK_Success;
}

static constexpr auto MAX_NUMBER_STRING_SIZE = 10;    // 4G
static constexpr auto MAX_EXTENSION_SIZE = 4;     // .xxx
static constexpr auto MAX_FILETITLE_SIZE = (MAX_NUMBER_STRING_SIZE + MAX_EXTENSION_SIZE + 1);  // null-terminated

AKRESULT FAkUnrealLegacyIOHook::GetFullFilePath(
	AkFileID			in_fileID,		// File name.
	AkFileSystemFlags * in_pFlags,			// Special flags. Can be NULL.
	AkOpenMode			in_eOpenMode,		// File open mode (read, write, ...).
	FString*			out_szFullFilePath // Full file path.
	)
{
	if (!in_pFlags ||
		!(in_pFlags->uCompanyID == AKCOMPANYID_AUDIOKINETIC || in_pFlags->uCompanyID == AKCOMPANYID_AUDIOKINETIC_EXTERNAL))
	{
		AKASSERT(!"Unhandled file type");
		return AK_InvalidParameter;
	}

	// Compute file name with file system paths.
	size_t uiPathSize = m_szBasePath.Len();

	// Copy base path. 
	*out_szFullFilePath = m_szBasePath;

	// Add language directory name if needed.
	if (in_pFlags->bIsLanguageSpecific)
	{
		auto currentLanguage = AK::StreamMgr::GetCurrentLanguage();
		size_t uLanguageStrLen = AKPLATFORM::OsStrLen(currentLanguage);
		if (uLanguageStrLen > 0)
		{
			uiPathSize += (uLanguageStrLen + 1);
			if (uiPathSize >= AK_MAX_PATH)
			{
				AKASSERT(!"Path is too large");
				return AK_InvalidParameter;
			}
			out_szFullFilePath->Append(currentLanguage);
			out_szFullFilePath->Append(FGenericPlatformMisc::GetDefaultPathSeparator());
		}
	}

	// Append file title.
	if ((uiPathSize + MAX_FILETITLE_SIZE) <= AK_MAX_PATH)
	{
		out_szFullFilePath->Append(FString::FromInt(in_fileID));
		if (in_pFlags->uCodecID == AKCODECID_BANK)
			out_szFullFilePath->Append(TEXT(".bnk"));
		else
			out_szFullFilePath->Append(TEXT(".wem"));
	}
	else
	{
		AKASSERT(!"String buffer too small");
		return AK_InvalidParameter;
	}

	return AK_Success;
}
