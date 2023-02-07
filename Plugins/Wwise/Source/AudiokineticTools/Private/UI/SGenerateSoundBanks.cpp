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
	SGenerateSoundBanks.cpp
------------------------------------------------------------------------------------*/

#include "SGenerateSoundBanks.h"

#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkSettingsPerUser.h"
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
#include "Widgets/Input/SCheckBox.h"
#include "WwiseProject/WwiseProjectInfo.h"

#define LOCTEXT_NAMESPACE "AkAudio"

SGenerateSoundBanks::SGenerateSoundBanks()
{
}

void SGenerateSoundBanks::Construct(const FArguments& InArgs)
{
	// Generate the list of banks and platforms
	PopulateList();
	if (PlatformNames.Num() == 0)
	{
		FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Warning_Ak_PlatformSupported", "Unable to generate Sound Data. Please select a valid Wwise supported platform in the 'Project Settings > Project > Supported Platforms' dialog."));
		return;
	}

	bool skipLanguages = false;

	if (auto* akSettingsPerUser = GetDefault<UAkSettingsPerUser>())
	{
		skipLanguages = akSettingsPerUser->SoundDataGenerationSkipLanguage;
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
					SAssignNew(PlatformList, SListView<TSharedPtr<FString>>)
					.ListItemsSource(&PlatformNames)
					.SelectionMode(ESelectionMode::Multi)
					.OnGenerateRow(this, &SGenerateSoundBanks::MakePlatformListItemWidget)
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
			+ SHorizontalBox::Slot()
			.Padding(0, 8)
			.AutoWidth()
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				[
					SAssignNew(LanguageList, SListView<TSharedPtr<FString>>)
					.ListItemsSource(&LanguagesNames)
					.SelectionMode(ESelectionMode::Multi)
					.OnGenerateRow(this, &SGenerateSoundBanks::MakePlatformListItemWidget)
					.HeaderRow
					(
						SNew(SHeaderRow)
						+ SHeaderRow::Column("Available Languages")
						[
							SNew(SBorder)
							.Padding(5)
							.Content()
							[
								SNew(STextBlock)
								.Text(LOCTEXT("AkAvailableLanguages", "Available Languages"))
							]
						]
					)
				]
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		.HAlign(HAlign_Left)
		[
			SAssignNew(SkipLanguagesCheckBox, SCheckBox)
			.IsChecked(skipLanguages ? ECheckBoxState::Checked : ECheckBoxState::Unchecked)
			.Content()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("AkSkipVOFiles", "Skip generation of localized assets"))
			]
		]
		+SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 4)
		.HAlign(HAlign_Right)
		[
			SNew(SButton)
			.Text(LOCTEXT("AkGenerate", "Generate"))
			.OnClicked(this, &SGenerateSoundBanks::OnGenerateButtonClicked)
		]
	];

	// Select all the platforms
	for (const auto& platform : PlatformNames)
	{
		PlatformList->SetItemSelection(platform, true);
	}

	// Select all the languages
	for (const auto& language : LanguagesNames)
	{
		LanguageList->SetItemSelection(language, true);
	}
}

void SGenerateSoundBanks::PopulateList(void)
{
	wwiseProjectInfo.Parse();

	// Get available platforms
	PlatformNames.Empty();
	auto AvailablePlatformNames = AkUnrealPlatformHelper::GetAllSupportedWwisePlatforms(true);
	TArray<FString> AvailablePlatformsInWwiseProject;
	for (auto SupportedPlatform : wwiseProjectInfo.GetSupportedPlatforms())
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

	LanguagesNames.Empty();
	for (const auto& language : wwiseProjectInfo.GetSupportedLanguages())
	{
		LanguagesNames.Add(MakeShared<FString>(language.Name));
	}
}

FReply SGenerateSoundBanks::OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyboardEvent )
{
	if( InKeyboardEvent.GetKey() == EKeys::Enter )
	{
		return OnGenerateButtonClicked();
	}
	else if( InKeyboardEvent.GetKey() == EKeys::Escape )
	{
		TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
		ParentWindow->RequestDestroyWindow();
		return FReply::Handled();
	}

	return SCompoundWidget::OnKeyDown(MyGeometry, InKeyboardEvent);
}

FReply SGenerateSoundBanks::OnGenerateButtonClicked()
{
	TArray< TSharedPtr<FString> > PlatformsToGenerate = PlatformList->GetSelectedItems();
	if( PlatformsToGenerate.Num() <= 0 )
	{
		FMessageDialog::Open( EAppMsgType::Ok, NSLOCTEXT("AkAudio", "Warning_Ak_NoAkPlatformsSelected", "At least one platform must be selected."));
		return FReply::Handled();
	}

	AkSoundDataBuilder::InitParameters initParameters;

	for (auto& platform : PlatformsToGenerate)
	{
		initParameters.Platforms.Add(*platform.Get());
	}

	TArray<TSharedPtr<FString>> languagesToGenerate = LanguageList->GetSelectedItems();

	for (auto& selectedLanguage : languagesToGenerate)
	{
		for (auto& entry : wwiseProjectInfo.GetSupportedLanguages())
		{
			if (*selectedLanguage == entry.Name)
			{
				initParameters.Languages.Add(entry);
				break;
			}
		}
	}

	initParameters.SkipLanguages = SkipLanguagesCheckBox->IsChecked();

	if (auto* akSettingsPerUser = GetMutableDefault<UAkSettingsPerUser>())
	{
		akSettingsPerUser->SoundDataGenerationSkipLanguage = initParameters.SkipLanguages;
		akSettingsPerUser->SaveConfig();
	}

	CookAkSoundDataTask::ExecuteTask(initParameters);

	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindWidgetWindow(AsShared());
	ParentWindow->RequestDestroyWindow();

	return FReply::Handled();
}

TSharedRef<ITableRow> SGenerateSoundBanks::MakePlatformListItemWidget(TSharedPtr<FString> Platform, const TSharedRef<STableViewBase>& OwnerTable)
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

#undef LOCTEXT_NAMESPACE
