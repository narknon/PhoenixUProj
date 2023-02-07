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
#include "AkWaapiClient.h"
#include "AkSettingsPerUser.generated.h"

DECLARE_EVENT(UAkSettingsPerUser, AutoConnectChanged);

UCLASS(config = EditorPerProjectUserSettings)
class AKAUDIO_API UAkSettingsPerUser : public UObject
{
	GENERATED_UCLASS_BODY()

	// Wwise Installation Path (Windows Authoring tool)
	UPROPERTY(Config, EditAnywhere, Category = "Installation")
	FDirectoryPath WwiseWindowsInstallationPath;

	// Wwise Installation Path (Mac Authoring tool)
	UPROPERTY(Config, EditAnywhere, Category = "Installation", meta = (FilePathFilter = "app", AbsolutePath))
	FFilePath WwiseMacInstallationPath;

	// Enable automatic asset synchronization with the new asset management system
	// Changes to this settings will only reflect after restarting the editor
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data")
	bool EnableAutomaticAssetSynchronization = false;

	// IP Address used to connect to WAAPI. Changing this requires Editor restart
	UPROPERTY(Config, EditAnywhere, Category = "WAAPI")
	FString WaapiIPAddress = WAAPI_LOCAL_HOST_IP_STRING;

	// Network Port used to connect to WAAPI. Changing this requires Editor restart
	UPROPERTY(Config, EditAnywhere, Category = "WAAPI")
	uint32 WaapiPort = WAAPI_PORT;

	// Whether to connect to WAAPI or not
	UPROPERTY(Config, EditAnywhere, Category = "WAAPI")
	bool bAutoConnectToWAAPI = false;

	// Whether to synchronize the selection between the WAAPI picker and the Wwise Project Explorer
	UPROPERTY(Config, EditAnywhere, Category = "WAAPI")
	bool AutoSyncSelection = true;

	UPROPERTY(Config)
	bool SuppressWwiseProjectPathWarnings = false;

	UPROPERTY(Config)
	bool SoundDataGenerationSkipLanguage = false;

public:
	mutable AutoConnectChanged OnAutoConnectChanged;

#if WITH_EDITOR
protected:
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#if UE_4_25_OR_LATER
	void PreEditChange(FProperty* PropertyAboutToChange) override;
#else
	void PreEditChange(UProperty* PropertyAboutToChange) override;
#endif

private:
	FString PreviousWwiseWindowsInstallationPath;
	FString PreviousWwiseMacInstallationPath;
#endif
};