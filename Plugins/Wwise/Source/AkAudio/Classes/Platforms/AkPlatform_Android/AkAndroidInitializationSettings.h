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

#include "Engine/EngineTypes.h"
#include "AkInclude.h"
#include "InitializationSettings/AkInitializationSettings.h"
#include "InitializationSettings/AkPlatformInitialisationSettingsBase.h"

#include "AkAndroidInitializationSettings.generated.h"

UENUM(Meta = (Bitmask))
enum class EAkAndroidAudioAPI : uint32
{
	AAudio,
	OpenSL_ES
};

USTRUCT()
struct FAkAndroidAdvancedInitializationSettings : public FAkAdvancedInitializationSettingsWithMultiCoreRendering
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (Bitmask, BitmaskEnum = EAkAndroidAudioAPI, ToolTip = "Main audio API to use. Leave set to \"Default\" for the default audio sink."))
	uint32 AudioAPI = (1 << (uint32)EAkAndroidAudioAPI::AAudio) | (1 << (uint32)EAkAndroidAudioAPI::OpenSL_ES);

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Used when hardware-preferred frame size and user-preferred frame size are not compatible. If true (default), the sound engine will initialize to a multiple of the HW setting, close to the user setting. If false, the user setting is used as is, regardless of the HW preference (might incur a performance hit)."))
	bool RoundFrameSizeToHardwareSize = true;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};


UCLASS(config = Game, defaultconfig)
class AKAUDIO_API UAkAndroidInitializationSettings : public UObject, public IAkPlatformInitialisationSettingsBase
{
	GENERATED_UCLASS_BODY()

public:
	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const override;

	UPROPERTY(Config, EditAnywhere, Category = "Initialization")
	FAkCommonInitializationSettingsWithSampleRate CommonSettings;

	UPROPERTY(Config, EditAnywhere, Category = "Initialization")
	FAkCommunicationSettingsWithSystemInitialization CommunicationSettings;

	UPROPERTY(Config, EditAnywhere, Category = "Initialization", AdvancedDisplay)
	FAkAndroidAdvancedInitializationSettings AdvancedSettings;

	UFUNCTION()
	void MigrateMultiCoreRendering(bool NewValue) 
	{
		AdvancedSettings.EnableMultiCoreRendering = NewValue;
	}
};
