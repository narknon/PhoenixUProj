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

#include "AkInclude.h"

class IAkUnrealIOHook : public AK::StreamMgr::IAkIOHookDeferred,
	public AK::StreamMgr::IAkFileLocationResolver
{
public:
	virtual ~IAkUnrealIOHook() {}

	virtual bool Init(const AkDeviceSettings& in_deviceSettings) = 0;

	virtual AKRESULT LoadFilePackage(
		const AkOSChar* in_pszFilePackageName,	// File package name. Location is resolved using base class' Open().
		AkUInt32& out_uPackageID			// Returned package ID.
		)
	{
		return AK_Success;
	}

	virtual AKRESULT UnloadAllFilePackages() { return AK_Success; }
};