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

#pragma once

#include "IAkUnrealIOHook.h"
#include "CoreUObject/Public/UObject/WeakObjectPtr.h"

class FAssetRegistryModule;
class UAkMediaAsset;
class UAkExternalMediaAsset;

class FAkUnrealIOHook : public IAkUnrealIOHook
{
public:
	FAkUnrealIOHook();
	virtual ~FAkUnrealIOHook();

	bool Init(const AkDeviceSettings& in_deviceSettings) override;

	/**
	 * Returns a file descriptor for a given file name (string).
	 *
	 * @param in_pszFileName	File name.
	 * @param in_eOpenMode		Open mode.
	 * @param in_pFlags			Special flags. Can pass NULL.
	 * @param io_bSyncOpen		If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
	 * @param out_fileDesc		Returned file descriptor.
	 * @return	AK_Success if operation was successful, error code otherwise
	 */
	AKRESULT Open(
		const AkOSChar*			in_pszFileName,
		AkOpenMode				in_eOpenMode,
		AkFileSystemFlags*		in_pFlags,
		bool&					io_bSyncOpen,
		AkFileDesc&			out_fileDesc
	) override;

	/**
	 * Returns a file descriptor for a given file ID.
	 *
	 * @param in_fileID			File ID.
	 * @param in_eOpenMode		Open mode.
	 * @param in_pFlags			Special flags. Can pass NULL.
	 * @param io_bSyncOpen		If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
	 * @param out_fileDesc		Returned file descriptor.
	 * @return	AK_Success if operation was successful, error code otherwise
	 */
	AKRESULT Open(
		AkFileID				in_fileID,          // File ID.
		AkOpenMode				in_eOpenMode,       // Open mode.
		AkFileSystemFlags*		in_pFlags,			// Special flags. Can pass NULL.
		bool&					io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
		AkFileDesc&			out_fileDesc        // Returned file descriptor.
	) override;

	/**
	 * Reads data from a file (asynchronous).
	 *
	 * @param in_fileDesc		File descriptor.
	 * @param in_heuristics		Heuristics for this data transfer.
	 * @param io_transferInfo	Asynchronous data transfer info.
	 * @return	AK_Success if operation was successful, error code otherwise
	 */
	AKRESULT Read(
		AkFileDesc &			in_fileDesc,
		const AkIoHeuristics &	in_heuristics,
		AkAsyncIOTransferInfo & io_transferInfo
	) override;

	// Writes data to a file (asynchronous).
	AKRESULT Write(
		AkFileDesc &			in_fileDesc,        // File descriptor.
		const AkIoHeuristics &	in_heuristics,		// Heuristics for this data transfer.
		AkAsyncIOTransferInfo & io_transferInfo		// Platform-specific asynchronous IO operation info.
	) override;

	virtual void Cancel(
		AkFileDesc &			in_fileDesc,
		AkAsyncIOTransferInfo & io_transferInfo,
		bool & io_bCancelAllTransfersForThisFile
	);

	/**
	 * Cleans up a file.
	 *
	 * @param in_fileDesc		File descriptor.
	 * @return	AK_Success if operation was successful, error code otherwise
	 */
	AKRESULT Close(AkFileDesc& in_fileDesc) override;

	// Returns the block size for the file or its storage device.
	AkUInt32 GetBlockSize(AkFileDesc& in_fileDesc) override;

	// Returns a description for the streaming device above this low-level hook.
	void GetDeviceDesc(AkDeviceDesc& out_deviceDesc) override;

	// Returns custom profiling data: 1 if file opens are asynchronous, 0 otherwise.
	AkUInt32 GetDeviceData() override;

	// And and remove streaming medias from the media map
	static void AddStreamingMedia(UAkMediaAsset* MediaToAdd);
	static void RemoveStreamingMedia(UAkMediaAsset* MediaToRemove);
	
	static void AddExternalMedia(UAkExternalMediaAsset* MediaToAdd);
	static void RemoveExternalMedia(TWeakObjectPtr<UAkExternalMediaAsset> MediaToRemove);
	

private:
	void CleanFileDescriptor(AkFileDesc& out_fileDesc);
	TWeakObjectPtr<UAkMediaAsset> GetStreamingAsset(const uint32 assetID);
	TWeakObjectPtr<UAkExternalMediaAsset> GetExternalSourceAsset(const FString &assetPath);
	AKRESULT DoAssetOpen(TWeakObjectPtr<UAkMediaAsset> MediaAsset, AkFileDesc& OutFileDesc);

private:
	AkDeviceID m_deviceID = AK_INVALID_DEVICE_ID;
	FAssetRegistryModule* assetRegistryModule = nullptr;
	FString mediaPackagePath;
	FString localizedPackagePath;

	static FCriticalSection MediaMapCriticalSection;
	static TMap<uint32, TArray<TWeakObjectPtr<UAkMediaAsset>>> StreamingMediaMap;
	static TMap<FString, TArray<TWeakObjectPtr<UAkExternalMediaAsset>>> ExternalMediaMap;
};
