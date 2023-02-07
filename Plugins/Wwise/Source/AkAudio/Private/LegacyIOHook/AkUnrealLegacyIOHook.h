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
// AkUnrealLegacyIOHook.h
//
// Implementation of the IO Hook redirecting 
// the Read requests into Unreal I/O system.
//
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "IAkUnrealIOHook.h"
#include "Async/AsyncFileHandle.h"

struct AkLegacyFileCustomParam
{
	virtual ~AkLegacyFileCustomParam() {}
	virtual AKRESULT DoWork(AkAsyncIOTransferInfo& io_transferInfo) = 0;

	virtual bool IsInPackage() { return false; }

	static AkLegacyFileCustomParam* GetFileCustomParam(const AkFileDesc& fileDesc);
	static void SetupFileDesc(AkFileDesc& fileDesc, AkLegacyFileCustomParam* FileCustomParam);
};

struct AkFileCustomParamInPackage : AkLegacyFileCustomParam
{
public:
	AkFileCustomParamInPackage(AkLegacyFileCustomParam* InWorker) :
		PackageCustomParam(InWorker) {}

	virtual AKRESULT  DoWork(AkAsyncIOTransferInfo& io_transferInfo) override { return PackageCustomParam->DoWork(io_transferInfo); }

	virtual bool IsInPackage() { return true; }

private:

	AkLegacyFileCustomParam* PackageCustomParam = nullptr;
};

class AkLegacyFileCustomParamPolicy
{
public:
	// Returns true if file described by in_fileDesc is in a package.
	static inline bool IsInPackage(const AkFileDesc& in_fileDesc)
	{
		auto FileCustomParam = AkLegacyFileCustomParam::GetFileCustomParam(in_fileDesc);
		return FileCustomParam && FileCustomParam->IsInPackage();
	}

	static inline void CloseFilePackageFile(const AkFileDesc& in_fileDesc)
	{
		auto FileCustomParam = AkLegacyFileCustomParam::GetFileCustomParam(in_fileDesc);
		delete FileCustomParam;
	}

	static inline AkUInt32 GetBlockSize(AkFileDesc& in_fileDesc)
	{
		return GetBlockSize();
	}

	static inline AkUInt32 GetBlockSize()
	{
#if PLATFORM_XBOXONE
        return 4096;
#else
        return 1;
#endif	
	}

	template<class T_PACKAGE, class T_ENTRY>
	static void SetInPackageFileDesc(AkFileDesc& out_fileDesc, T_PACKAGE* in_pPackage, const T_ENTRY* in_pEntry)
	{
		// File descriptor custom param should not already exist otherwise we will be leaking memory
		check(AkLegacyFileCustomParam::GetFileCustomParam(out_fileDesc) == nullptr);

		AkLegacyFileCustomParam::SetupFileDesc(out_fileDesc,
			new AkFileCustomParamInPackage(AkLegacyFileCustomParam::GetFileCustomParam(*in_pPackage->GetFileDesc())));
	}
};

//-----------------------------------------------------------------------------
// Name: class FAkUnrealLegacyIOHook.
// Desc: Implements IAkIOHookDeferred low-level I/O hook, and 
//		 IAkFileLocationResolver. Can be used as a standalone Low-Level I/O
//		 system, or as part of a system with multiple devices.
//		 File location is resolved using simple path concatenation logic
//		 (implemented in CAkFileLocationBase).
//-----------------------------------------------------------------------------
class FAkUnrealLegacyIOHook : public IAkUnrealIOHook
{
public:
	virtual ~FAkUnrealLegacyIOHook();

	/** 
	 * Initialization. Init() registers this object as the one and 
	 * only File Location Resolver if none were registered before. Then 
	 * it creates a streaming device with scheduler type AK_SCHEDULER_DEFERRED_LINED_UP.
	 *
	 * @param in_deviceSettings		Device settings.
	 * @return	true if initialization was successful, false otherwise
	 */
	bool Init(const AkDeviceSettings& in_deviceSettings) override;

	//
	// IAkFileLocationAware interface.
	//-----------------------------------------------------------------------------

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
        AkFileSystemFlags *		in_pFlags,			
		bool &					io_bSyncOpen,		
        AkFileDesc &			out_fileDesc        
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
        AkFileSystemFlags *		in_pFlags,			// Special flags. Can pass NULL.
		bool &					io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
        AkFileDesc &			out_fileDesc        // Returned file descriptor.
        ) override;

	//
	// IAkIOHookDeferred interface.
	//-----------------------------------------------------------------------------

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

    /**
	 * Notifies that a transfer request is cancelled. It will be flushed by the streaming device when completed.
	 *
	 * @param in_fileDesc							File descriptor.
	 * @param io_transferInfo						Transfer info to cancel.
	 * @param io_bCancelAllTransfersForThisFile		Flag indicating whether all transfers should be cancelled for this file (see notes in function description).
	 */
    void Cancel(
		AkFileDesc &			in_fileDesc,
		AkAsyncIOTransferInfo & io_transferInfo,
		bool & io_bCancelAllTransfersForThisFile
	) override;

	/**
	 * Cleans up a file.
	 *
	 * @param in_fileDesc		File descriptor.
	 * @return	AK_Success if operation was successful, error code otherwise
	 */
	virtual AKRESULT Close(
        AkFileDesc &			in_fileDesc
        );

    // Returns the block size for the file or its storage device. 
    virtual AkUInt32 GetBlockSize(
        AkFileDesc &  			in_fileDesc			// File descriptor.
        );

	// Returns a description for the streaming device above this low-level hook.
    virtual void GetDeviceDesc(
        AkDeviceDesc &  		out_deviceDesc      // Description of associated low-level I/O device.
        );
	
	// Returns custom profiling data: 1 if file opens are asynchronous, 0 otherwise.
	virtual AkUInt32 GetDeviceData();

	// String overload.
	// Returns AK_Success if input flags are supported and the resulting path is not too long.
	// Returns AK_Fail otherwise.
	AKRESULT GetFullFilePath(
		const FString&		in_szFileName,		// File name.
		AkFileSystemFlags * in_pFlags,			// Special flags. Can be NULL.
		AkOpenMode			in_eOpenMode,		// File open mode (read, write, ...).
		FString*			out_szFullFilePath	// Full file path.
		);

	// ID overload.
	// Returns AK_Success if input flags are supported and the resulting path is not too long.
	// Returns AK_Fail otherwise.
	AKRESULT GetFullFilePath(
		AkFileID			in_fileID,			// File ID.
		AkFileSystemFlags * in_pFlags,			// Special flags. Can be NULL.
		AkOpenMode			in_eOpenMode,		// File open mode (read, write, ...).
		FString*			out_szFullFilePath	// Full file path.
		);

protected:
	// Base path, where the SoundBanks are located.
	FString m_szBasePath;

private:
	/** 
	 * Reset the file descriptor
	 *
	 * @param out_fileDesc The file descriptor
	 */
	void CleanFileDescriptor( AkFileDesc& out_fileDesc );

	/**
	 * Perform the open, whether we have a file ID or a file Name
	 *
	 * @param in_fileDescriptor		file ID or file Name
	 * @param in_eOpenMode			Open mode.
	 * @param in_pFlags				Special flags. Can pass NULL.
	 * @param io_bSyncOpen			If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
	 * @param out_fileDesc			Returned file descriptor.
	 * @return AK_Success if operation was successful, error code otherwise
	 */
	template<typename T>
	AKRESULT PerformOpen( 
		T				in_fileDescriptor,  // Can be file ID or file Name
		AkOpenMode      in_eOpenMode,       // Open mode.
		AkFileSystemFlags * in_pFlags,      // Special flags. Can pass NULL.
		bool &			io_bSyncOpen,		// If true, the file must be opened synchronously. Otherwise it is left at the File Location Resolver's discretion. Return false if Open needs to be deferred.
		AkFileDesc &    out_fileDesc        // Returned file descriptor.
		);

	bool m_bAsyncOpen = false;	// If true, opens files asynchronously when it can.

protected:
	AkDeviceID m_deviceID = AK_INVALID_DEVICE_ID;
};
