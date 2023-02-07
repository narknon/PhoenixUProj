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


#include "AkCustomVersion.h"
#include "AkAudioDevice.h"
#include "Serialization/CustomVersion.h"

const FGuid FAkCustomVersion::GUID(0xE2717C7E, 0x52F544D3, 0x950C5340, 0xB315035E);

// Register the custom version with core
FCustomVersionRegistration GRegisterAkCustomVersion(FAkCustomVersion::GUID, FAkCustomVersion::LatestVersion, TEXT("AkAudioVersion"));
