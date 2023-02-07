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

#include "AkSettingsPerUser.h"

#include "AkAudioDevice.h"
#include "Misc/Paths.h"
#include "AkUnrealHelper.h"

#if WITH_EDITOR
#include "Core/Public/Modules/ModuleManager.h"
#include "SettingsEditor/Public/ISettingsEditorModule.h"
#endif
//////////////////////////////////////////////////////////////////////////
// UAkSettingsPerUser

UAkSettingsPerUser::UAkSettingsPerUser(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
#if UE_4_21_OR_LATER
	WwiseWindowsInstallationPath.Path = FPlatformMisc::GetEnvironmentVariable(TEXT("WWISEROOT"));
#else
	TCHAR WwiseDir[AK_MAX_PATH];
	FPlatformMisc::GetEnvironmentVariable(TEXT("WWISEROOT"), WwiseDir, AK_MAX_PATH);

	WwiseWindowsInstallationPath.Path = FString(WwiseDir);
#endif
#endif
}

#if WITH_EDITOR
#if UE_4_25_OR_LATER
void UAkSettingsPerUser::PreEditChange(FProperty* PropertyAboutToChange)
#else
void UAkSettingsPerUser::PreEditChange(UProperty* PropertyAboutToChange)
#endif
{
	PreviousWwiseWindowsInstallationPath = WwiseWindowsInstallationPath.Path;
	PreviousWwiseMacInstallationPath = WwiseMacInstallationPath.FilePath;
}

void UAkSettingsPerUser::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	const FName MemberPropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;

	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSettingsPerUser, WwiseWindowsInstallationPath))
	{
		AkUnrealHelper::SanitizePath(WwiseWindowsInstallationPath.Path, PreviousWwiseWindowsInstallationPath, FText::FromString("Please enter a valid Wwise Installation path"));
	}
	else if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSettingsPerUser, WwiseMacInstallationPath))
	{
		AkUnrealHelper::SanitizePath(WwiseMacInstallationPath.FilePath, PreviousWwiseMacInstallationPath, FText::FromString("Please enter a valid Wwise Authoring Mac executable path"));
	}
	else if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSettingsPerUser, bAutoConnectToWAAPI))
	{
		OnAutoConnectChanged.Broadcast();
	}
	else if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSettingsPerUser, EnableAutomaticAssetSynchronization))
	{
		ISettingsEditorModule& SettingsEditorModule = FModuleManager::GetModuleChecked<ISettingsEditorModule>("SettingsEditor");
		SettingsEditorModule.OnApplicationRestartRequired();
	}


	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif
