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

#include "SAkAudioBankPicker.h"

#include "AkAudioBank.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Factories/AkAssetFactories.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "IContentBrowserSingleton.h"
#include "Styling/SlateIconFinder.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"

#define LOCTEXT_NAMESPACE "AkAudio"

SAkAudioBankPicker::SAkAudioBankPicker()
{
}

void SAkAudioBankPicker::Construct(const FArguments& InArgs)
{
	WidgetWindow = InArgs._WidgetWindow;

	FMenuBuilder MenuBuilder(false, nullptr, nullptr, false);

	auto* akAudioBankFactory = GetDefault<UAkAudioBankFactory>();

	MenuBuilder.BeginSection(NAME_None, LOCTEXT("CreateNewAsset", "Create New Asset"));
	{
		MenuBuilder.AddMenuEntry(
			akAudioBankFactory->GetDisplayName(),
			akAudioBankFactory->GetToolTip(),
			FSlateIconFinder::FindIconForClass(akAudioBankFactory->GetSupportedClass()),
			FUIAction(FExecuteAction::CreateSP(this, &SAkAudioBankPicker::OnCreateNewAssetSelected))
		);
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection(NAME_None, LOCTEXT("BrowseHeader", "Browse"));
	{
		TSharedPtr<SWidget> MenuContent;

		FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

		FAssetPickerConfig AssetPickerConfig;
		AssetPickerConfig.Filter.ClassNames.Add(UAkAudioBank::StaticClass()->GetFName());

		// Allow child classes
		AssetPickerConfig.Filter.bRecursiveClasses = true;
		// Set a delegate for setting the asset from the picker
		AssetPickerConfig.OnAssetSelected = FOnAssetSelected::CreateSP(this, &SAkAudioBankPicker::OnAssetSelected);
		// Set a delegate for setting the asset from the picker via the keyboard
		AssetPickerConfig.OnAssetEnterPressed = FOnAssetEnterPressed::CreateSP(this, &SAkAudioBankPicker::OnAssetEnterPressed);
		AssetPickerConfig.OnAssetDoubleClicked = FOnAssetDoubleClicked::CreateSP(this, &SAkAudioBankPicker::OnAssetDoubleClicked);
		// Use the list view by default
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
		// We'll do clearing ourselves
		AssetPickerConfig.bAllowNullSelection = false;
		// Focus search box
		AssetPickerConfig.bFocusSearchBoxWhenOpened = true;
		// Don't allow dragging
		AssetPickerConfig.bAllowDragging = false;
		AssetPickerConfig.SelectionMode = ESelectionMode::Single;
		// Save the settings into a special section for asset pickers for properties
		AssetPickerConfig.SaveSettingsName = TEXT("SAkAudioBankPicker");

		MenuContent =
			SNew(SBox)
			[
				ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
			];

		MenuBuilder.AddWidget(MenuContent.ToSharedRef(), FText::GetEmpty(), true);
	}
	MenuBuilder.EndSection();

	// Build the form
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			MenuBuilder.MakeWidget()
		]
		+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Right)
			.Padding(2)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(2)
				+ SUniformGridPanel::Slot(0, 0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("SAkAudioBankPicker_SelectButton", "Select"))
					.ToolTipText(LOCTEXT("SAkAudioBankPicker_SelectButton_Tooltip", "Set the AkAudioBank for the selected events"))
					.IsEnabled(this, &SAkAudioBankPicker::CanSelect)
					.OnClicked(this, &SAkAudioBankPicker::CloseWindow)
				]
				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("SAkAudioBankPicker_Cancel", "Cancel"))
					.ToolTipText(LOCTEXT("SAkAudioBankPicker_Cancel_ToolTip", "Close the window"))
					.OnClicked(this, &SAkAudioBankPicker::OnCancel)
				]
			]
	];
}

void SAkAudioBankPicker::OnCreateNewAssetSelected()
{
	if (auto* akAudioBankFactory = GetDefault<UAkAudioBankFactory>())
	{
		UFactory* FactoryInstance = DuplicateObject<UFactory>(akAudioBankFactory, GetTransientPackage());
		FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();
		UObject* NewAsset = AssetToolsModule.Get().CreateAssetWithDialog(FactoryInstance->GetSupportedClass(), FactoryInstance);
		if (NewAsset != nullptr)
		{
			SelectedAkEventGroup = FAssetData(NewAsset);
		}
	}
}

void SAkAudioBankPicker::OnAssetSelected(const FAssetData& AssetData)
{
	SelectedAkEventGroup = AssetData;
}

void SAkAudioBankPicker::OnAssetDoubleClicked(const FAssetData& AssetData)
{
	SelectedAkEventGroup = AssetData;

	WidgetWindow.Pin()->RequestDestroyWindow();
}

void SAkAudioBankPicker::OnAssetEnterPressed(const TArray<FAssetData>& AssetData)
{
	if (AssetData.Num() > 0)
	{
		SelectedAkEventGroup = AssetData[0];
	}
}

bool SAkAudioBankPicker::CanSelect() const
{
	return SelectedAkEventGroup.IsValid();
}

FReply SAkAudioBankPicker::CloseWindow()
{
	WidgetWindow.Pin()->RequestDestroyWindow();

	return FReply::Handled();
}

FReply SAkAudioBankPicker::OnCancel()
{
	SelectedAkEventGroup = FAssetData();

	WidgetWindow.Pin()->RequestDestroyWindow();

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE