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


/*------------------------------------------------------------------------------------
	SLegacyGenerateSoundBanks.cpp
------------------------------------------------------------------------------------*/

#include "SLegacyGenerateSoundBanks.h"

#include "AkAudioBank.h"
#include "AkAudioDevice.h"
#include "AkWaapiClient.h"
#include "AkSettings.h"
#include "AkUnrealHelper.h"
#include "AssetManagement/AkSoundDataBuilder.h"
#include "AssetManagement/CookAkSoundDataTask.h"
#include "AssetRegistryModule.h"
#include "Dialogs/Dialogs.h"
#include "Dom/JsonObject.h"
#include "EditorStyleSet.h"
#include "Framework/Application/SlateApplication.h"
#include "GenericPlatform/GenericPlatformFile.h"
#if UE_5_0_OR_LATER
#include "HAL/PlatformFileManager.h"
#else
#include "HAL/PlatformFilemanager.h"
#endif
#include "Interfaces/ITargetPlatform.h"
#include "Interfaces/ITargetPlatformManagerModule.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "Platforms/AkPlatformInfo.h"
#include "Platforms/AkUEPlatform.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Widgets/Input/SButton.h"
#include "WwiseProject/WwiseProjectInfo.h"
#include "Settings/ProjectPackagingSettings.h"
#include "AssetRegistryModule.h"

#define LOCTEXT_NAMESPACE "AkAudio"

SLegacyGenerateSoundBanks::SLegacyGenerateSoundBanks()
{
}

void SLegacyGenerateSoundBanks::Construct(const FArguments& InArgs, TArray<TWeakObjectPtr<UAkAudioBank>>* in_pSoundBanks)
{
	// Generate the list of banks and platforms
	PopulateList();
	if (PlatformNames.Num() == 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Warning_Ak_PlatformSupported", "Unable to generate SoundBanks. Please select a valid Wwise supported platform in the 'Project Settings > Project > Supported Platforms' dialog."));
		return;
	}

	// Build the form
	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.Padding(0, 8)
		.FillHeight(1.f)
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.Padding(0, 8)
			.AutoWidth()
			[
				SNew(SBorder)
				.BorderImage( FEditorStyle::GetBrush("ToolPanel.GroupBorder") )
				[
					SAssignNew(BankList, SListView<TSharedPtr<FString>>)
					.ListItemsSource(&Banks)
					.SelectionMode(ESelectionMode::Multi)
					.OnGenerateRow(this, &SLegacyGenerateSoundBanks::MakeBankListItemWidget)
					.HeaderRow
					(
						SNew(SHeaderRow)
						+ SHeaderRow::Column("Available Banks")
						[
							SNew(SBorder)
							.Padding(5)
							.Content()
							[
								SNew(STextBlock)
								.Text(LOCTEXT("AkAvailableBanks", "Available Banks"))
							]
						]
					)
				]
			]
			+SHorizontalBox::Slot()
			.Padding(0, 8)
			.AutoWidth()
			[
				SNew(SBorder)
				.BorderImage( FEditorStyle::GetBrush("ToolPanel.GroupBorder") )
				[
					SAssignNew(PlatformList, SListView<TSharedPtr<FString>>)
					.ListItemsSource(&PlatformNames)
					.SelectionMode(ESelectionMode::Multi)
					.OnGenerateRow(this, &SLegacyGenerateSoundBanks::MakePlatformListItemWidget)
					.HeaderRow
					(
						SNew(SHeaderRow)
						+ SHeaderRow::Column("Available Platforms")
						[
							SNew(SBorder)
							.Padding(5)
							.Content()
							[
								SNew(STextBlock)
								.Text(LOCTEXT("AkAvailablePlatforms", "Available Platforms"))
							]
						]
					)
				]
			]
		]
		+SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		.HAlign(HAlign_Right)
		[
			SNew(SButton)
			.Text(LOCTEXT("AkGenerate", "Generate"))
			.OnClicked(this, &SLegacyGenerateSoundBanks::OnGenerateButtonClicked)
		]
	];


	// Select all the banks, or only the banks passed with pObjects
	if(in_pSoundBanks == nullptr)
	{
		// Select all the banks
		for (auto& BankName : Banks)
		{
			BankList->SetItemSelection(BankName, true);
		}
	}
	else
	{
		// Select given banks
		for (const auto& SoundBank : *in_pSoundBanks)
		{
			const auto inBankName = SoundBank->GetName();
			for (auto& BankName : Banks)
			{
				if (*BankName == inBankName)
				{
					BankList->SetItemSelection(BankName, true);
				}
			}
		}
	}

	// Select all the platforms
	for (int32 ItemIdx = 0; ItemIdx < PlatformNames.Num(); ItemIdx++)
	{
		PlatformList->SetItemSelection(PlatformNames[ItemIdx], true);
	}
}

void SLegacyGenerateSoundBanks::SetShouldSaveWwiseProject(bool in_bShouldSaveBeforeGeneration) { m_bShouldSaveWwiseProject = in_bShouldSaveBeforeGeneration; }

void SLegacyGenerateSoundBanks::PopulateList()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	Banks.Empty();

	// Force load of bank assets so that the list is fully populated.
	{
		TArray<FAssetData> BankAssets;
		AssetRegistryModule.Get().GetAssetsByClass(UAkAudioBank::StaticClass()->GetFName(), BankAssets);

		for(auto& bankAssetData : BankAssets)
		{	
			Banks.Add(MakeShared<FString>(bankAssetData.AssetName.ToString()));
		}
	}
	Banks.Sort([](const TSharedPtr<FString>& LHS, const TSharedPtr<FString>& RHS)
	{
		return *LHS < *RHS;
	});

	WwiseProjectInfo projectInfo;
	projectInfo.Parse();

	// Get available platforms
	PlatformNames.Empty();
	auto AvailablePlatformNames = AkUnrealPlatformHelper::GetAllSupportedWwisePlatforms(true);
	TArray<FString> AvailablePlatformsInWwiseProject;
	for (auto SupportedPlatform : projectInfo.GetSupportedPlatforms())
	{
		AvailablePlatformsInWwiseProject.Add(SupportedPlatform.Name);
	}
	for (const auto& Platform : AvailablePlatformNames)
	{
		auto* PlatformInfo = UAkPlatformInfo::GetAkPlatformInfo(*Platform);
		if (!PlatformInfo)
		{
			continue;
		}

		FString WwisePlatformName = PlatformInfo->GetWwiseBankPlatformName(AvailablePlatformsInWwiseProject);

		if (!WwisePlatformName.IsEmpty() &&
			!PlatformNames.ContainsByPredicate([WwisePlatformName](TSharedPtr<FString> Platform) { return WwisePlatformName == *Platform; }))
		{
			PlatformNames.Add(MakeShared<FString>(WwisePlatformName));
		}
	}
}

FReply SLegacyGenerateSoundBanks::OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyboardEvent )
{
	if (InKeyboardEvent.GetKey() == EKeys::Enter)
	{
		return OnGenerateButtonClicked();
	}
	else if (InKeyboardEvent.GetKey() == EKeys::Escape)
	{
		TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
		ParentWindow->RequestDestroyWindow();
		return FReply::Handled();
	}

	return SCompoundWidget::OnKeyDown(MyGeometry, InKeyboardEvent);
}

FReply SLegacyGenerateSoundBanks::OnGenerateButtonClicked()
{
	if (!EnsureSoundBankPathIsInPackagingSettings())
	{
		return FReply::Handled();
	}

	auto BanksToGenerate = BankList->GetSelectedItems();
	if (BanksToGenerate.Num() <= 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Warning_Ak_NoAkBanksSelected", "At least one bank must be selected."));
		return FReply::Handled();
	}

	auto PlatformsToGenerate = PlatformList->GetSelectedItems();
	if (PlatformsToGenerate.Num() <= 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Warning_Ak_NoAkPlatformsSelected", "At least one platform must be selected."));
		return FReply::Handled();
	}

	AkSoundDataBuilder::InitParameters initParameters;

	for (auto& platform : PlatformsToGenerate)
	{
		initParameters.Platforms.Add(*platform.Get());
	}

	for (auto& bank : BanksToGenerate)
	{
		initParameters.BanksToGenerate.Add(*bank.Get());
	}

	if (m_bShouldSaveWwiseProject)
	{
		/* If we have an open connection to Authoring via WAAPI, save the project first and wait until it is not dirty before generating sounbanks */
		FAkWaapiClient* pWaapiClient = FAkWaapiClient::Get();
		if (pWaapiClient != nullptr)
		{
			FAkWaapiClient::SaveProject();
			bool bProjectDirty = true;
			while (bProjectDirty)
			{
				bProjectDirty = FAkWaapiClient::IsProjectDirty();
			}
		}
	}

	CookAkSoundDataTask::ExecuteTask(initParameters);

	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
	ParentWindow->RequestDestroyWindow();

	return FReply::Handled();
}

TSharedRef<ITableRow> SLegacyGenerateSoundBanks::MakeBankListItemWidget(TSharedPtr<FString> Bank, const TSharedRef<STableViewBase>& OwnerTable)
{
	check(Bank.IsValid());

	return
		SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		[
			SNew(SBox)
			.WidthOverride(300)
			[
				SNew(STextBlock)
				.Text(FText::FromString(*Bank))
			]
		];
}

TSharedRef<ITableRow> SLegacyGenerateSoundBanks::MakePlatformListItemWidget(TSharedPtr<FString> Platform, const TSharedRef<STableViewBase>& OwnerTable)
{
	return
		SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		[
			SNew(SBox)
			.WidthOverride(300)
			[
				SNew(STextBlock)
				.Text(FText::FromString(*Platform))
			]
		];
}

bool SLegacyGenerateSoundBanks::EnsureSoundBankPathIsInPackagingSettings()
{
	UProjectPackagingSettings* PackagingSettings = GetMutableDefault<UProjectPackagingSettings>();

	FString SoundBankFolder = TEXT("WwiseAudio");
	if (const UAkSettings* AkSettings = GetDefault<UAkSettings>())
	{
		SoundBankFolder = AkSettings->WwiseSoundDataFolder.Path;
	}

	{
		TArray<FAssetData> AssetsFound;
		FString AssetPath = FString(TEXT("/Game")) / SoundBankFolder;
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		AssetRegistryModule.Get().GetAssetsByPath(FName(*AssetPath), AssetsFound, true);
		if (AssetsFound.Num() > 0)
		{
			FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Error_SBFolderContainsAssets", "Unable to generate SoundBanks. Please ensure your Sound Data folder does not contain Unreal Assets. It should only contain SoundBank files."));
			return false;
		}
	}


	bool foundPackageDirectory = false;
	bool packageSettingsNeedUpdate = false;

	for (int32 i = 0; i < PackagingSettings->DirectoriesToAlwaysStageAsUFS.Num(); i++)
	{
		if (PackagingSettings->DirectoriesToAlwaysStageAsUFS[i].Path == SoundBankFolder)
		{
			foundPackageDirectory = true;
			break;
		}
	}

	if (!foundPackageDirectory)
	{
		FDirectoryPath Path;
		Path.Path = SoundBankFolder;
		PackagingSettings->DirectoriesToAlwaysStageAsUFS.Add(Path);
		packageSettingsNeedUpdate = true;
	}

	if (packageSettingsNeedUpdate)
	{
		AkUnrealHelper::SaveConfigFile(PackagingSettings);
	}

	return true;
}

#undef LOCTEXT_NAMESPACE
