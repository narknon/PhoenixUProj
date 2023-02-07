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

#include "AkSettingsDetailsCustomization.h"
#include "AkSettings.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IStructureDetailsView.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SButton.h"
#include "Editor.h"

#define LOCTEXT_NAMESPACE "AudiokineticTools"

/** Dialog widget used to display function properties */
class SDecayKeyEntryDialog : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SDecayKeyEntryDialog) {}
	SLATE_END_ARGS()

	// We call this from a delegate that is called when the window has correctly been added to the slate application.
	// See FAkSettingsDetailsCustomization::InsertKeyModal.
	void FocusNumericEntryBox()
	{
		if (numberBox != nullptr)
		{
			FSlateApplication::Get().ClearAllUserFocus();
			FSlateApplication::Get().SetAllUserFocus(numberBox);
			FSlateApplication::Get().ClearKeyboardFocus();
			FSlateApplication::Get().SetKeyboardFocus(numberBox);
		}
	}

	void Construct(const FArguments& InArgs, TWeakPtr<SWindow> InParentWindow, float& decay)
	{
		bCommitted = false;
		ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.Padding(2.0f)
					.AutoHeight()
					[
						SAssignNew(numberBox, SNumericEntryBox<float>)
						.MinValue(0.0f)
						.MaxValue(100.0f)
						.Value_Lambda([&decay]() {return decay;})
						.OnValueCommitted_Lambda([this, InParentWindow, &decay](const float& value, ETextCommit::Type commitType)
						{
							if (commitType == ETextCommit::Type::OnCleared)
								decay = 0.0f;
							else
								decay = value;

							if (commitType == ETextCommit::OnEnter)
							{
								bCommitted = true;
								if (InParentWindow.IsValid())
								{
									InParentWindow.Pin()->RequestDestroyWindow();
								}
							}
						})
						.OnValueChanged_Lambda([&decay](const float& value)
						{
							decay = value;
						})
					]
					+ SVerticalBox::Slot()
					.Padding(2.0f)
					.AutoHeight()
					[
						SNew(SButton)
						.ForegroundColor(FLinearColor::White)
						.OnClicked_Lambda([this, InParentWindow, InArgs]()
						{
							if (InParentWindow.IsValid())
							{
								InParentWindow.Pin()->RequestDestroyWindow();
							}
							bCommitted = true;
							return FReply::Handled();
							})
						.ToolTipText(FText::FromString("Insert given key value"))
						[
							SNew(STextBlock)
							.TextStyle(FEditorStyle::Get(), "FlatButton.DefaultTextStyle")
							.Text(FText::FromString("Insert"))
						]
					]
				]
			]
		];
	}

	bool bCommitted = false;
	TSharedPtr<SNumericEntryBox<float>> numberBox = nullptr;
};

/** Dialog widget used to display function properties */
class SClearWarningDialog : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SClearWarningDialog) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TWeakPtr<SWindow> InParentWindow)
	{
		bOKPressed = false;
		ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.Padding(2.0f)
					.AutoHeight()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Warning: This will remove all aux bus values in the map. Do you want to continue?"))
					]
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(2.0f)
					.AutoWidth()
					[
						SNew(SButton)
						.ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
						.ForegroundColor(FLinearColor::White)
						.OnClicked_Lambda([this, InParentWindow, InArgs]()
						{
							if (InParentWindow.IsValid())
							{
								InParentWindow.Pin()->RequestDestroyWindow();
							}
							bOKPressed = true;
							return FReply::Handled();
						})
						.ToolTipText(FText::FromString("Clear aux bus assignment map"))
						[
							SNew(STextBlock)
							.TextStyle(FEditorStyle::Get(), "FlatButton.DefaultTextStyle")
							.Text(FText::FromString("Clear"))
						]
					]
					+ SHorizontalBox::Slot()
					.Padding(2.0f)
					.AutoWidth()
					[
						SNew(SButton)
						.ButtonStyle(FEditorStyle::Get(), "FlatButton.Default")
						.ForegroundColor(FLinearColor::White)
						.OnClicked_Lambda([this, InParentWindow, InArgs]()
						{
							if (InParentWindow.IsValid())
							{
								InParentWindow.Pin()->RequestDestroyWindow();
							}
							return FReply::Handled();
						})
						.ToolTipText(FText::FromString("Cancel"))
						[
							SNew(STextBlock)
							.TextStyle(FEditorStyle::Get(), "FlatButton.DefaultTextStyle")
							.Text(FText::FromString("Cancel"))
						]
					]
				]
			]
		];
	}

	bool bOKPressed;
};

TSharedRef<IDetailCustomization> FAkSettingsDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FAkSettingsDetailsCustomization);
}

void FAkSettingsDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	IDetailCategoryBuilder& CategoryBuilder = DetailLayout.EditCategory("Reverb Assignment Map", FText::GetEmpty(), ECategoryPriority::Uncommon);
	CategoryBuilder.AddCustomRow(FText::FromString("Clear Map")).WholeRowContent()
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().AutoHeight().Padding(2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
			[
				SNew(SButton)
				.Text(FText::FromString("Clear Map"))
				.ToolTipText(FText::FromString("Clear all of the entries in the map"))
				.OnClicked_Raw(this, &FAkSettingsDetailsCustomization::ClearAkSettingsRoomDecayAuxBusMap)
			]
			+ SHorizontalBox::Slot().FillWidth(8)
		]
		+ SVerticalBox::Slot().AutoHeight().Padding(2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
			[
				SNew(SButton)
				.Text(FText::FromString("Insert Decay Key"))
				.OnClicked_Raw(this, &FAkSettingsDetailsCustomization::InsertKeyModal)
			]
			+ SHorizontalBox::Slot().FillWidth(8)
		]
	];
}

FReply FAkSettingsDetailsCustomization::ClearAkSettingsRoomDecayAuxBusMap()
{
	// pop up a dialog to input params to the function
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString("Clear aux bus assignment map?"))
		.ScreenPosition(FSlateApplication::Get().GetCursorPos())
		.AutoCenter(EAutoCenter::None)
		.SizingRule(ESizingRule::Autosized)
		.SupportsMinimize(false)
		.SupportsMaximize(false);

	TSharedPtr<SClearWarningDialog> Dialog;
	Window->SetContent(SAssignNew(Dialog, SClearWarningDialog, Window));

	GEditor->EditorAddModalWindow(Window);

	if (Dialog->bOKPressed)
	{
		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		if (AkSettings != nullptr)
			AkSettings->ClearAkRoomDecayAuxBusMap();
	}

	return FReply::Handled();
}

FReply FAkSettingsDetailsCustomization::InsertKeyModal()
{
	// pop up a dialog to input params to the function
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString("Insert Decay Key"))
		.ScreenPosition(FSlateApplication::Get().GetCursorPos())
		.AutoCenter(EAutoCenter::None)
		.SizingRule(ESizingRule::Autosized)
		.SupportsMinimize(false)
		.SupportsMaximize(false);

	float decay = 0.0f;
	TSharedPtr<SDecayKeyEntryDialog> Dialog;
	Window->SetContent(SAssignNew(Dialog, SDecayKeyEntryDialog, Window, decay));

	// In order to give focus to the textbox in SDecayKeyEntryDialog when the dialog is created,
	// we need to wait until the window has been added to the slate application. If we try to focus the 
	// text box during the construction of the dialog, the window will not be found in the slate application's
	// list of top level windows, and the text box will not be focused. 
	// To achieve this, we need to set up a delegate to call after the modal window has been added to the slate application.
	FModalWindowStackStarted modalWindowCallback;
	modalWindowCallback.BindLambda([&Dialog]() 
	{
		if (Dialog.IsValid())
			Dialog->FocusNumericEntryBox(); 
	});
	FSlateApplication::Get().SetModalWindowStackStartedDelegate(modalWindowCallback);

	// During this call, the ModalWindowStackStartedDelegate will be called.
	GEditor->EditorAddModalWindow(Window);

	// Clear the ModalWindowStackStartedDelegate.
	FSlateApplication::Get().SetModalWindowStackStartedDelegate(nullptr);

	if (Dialog->bCommitted)
	{
		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		if (AkSettings != nullptr)
			AkSettings->InsertDecayKeyValue(decay);
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
