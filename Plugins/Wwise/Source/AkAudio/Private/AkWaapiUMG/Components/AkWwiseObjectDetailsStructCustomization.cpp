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

#if WITH_EDITOR

#include "AkWaapiUMG/Components/AkWwiseObjectDetailsStructCustomization.h"
#include "AkAudioDevice.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "DetailWidgetRow.h"
#include "AkAudioStyle.h"

#if UE_5_0_OR_LATER
#include "Framework/Docking/TabManager.h"
#endif

#define LOCTEXT_NAMESPACE "AkWwiseObjectDetailsStructCustomization"

TSharedRef<IPropertyTypeCustomization> FAkWwiseObjectDetailsStructCustomization::MakeInstance()
{
	return MakeShareable(new FAkWwiseObjectDetailsStructCustomization());
}

void FAkWwiseObjectDetailsStructCustomization::CustomizeHeader( TSharedRef<IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils )
{
	ItemNameProperty = StructPropertyHandle->GetChildHandle("ItemName");
	ItemPathProperty = StructPropertyHandle->GetChildHandle("ItemPath");
	ItemIdProperty = StructPropertyHandle->GetChildHandle("ItemId");
	
	if(ItemNameProperty.IsValid())
	{
		TSharedPtr<SWidget> PickerWidget = nullptr;

			PickerWidget = SAssignNew(PickerButton, SButton)
			.ButtonStyle(FAkAudioStyle::Get(), "AudiokineticTools.HoverHintOnly" )
			.ToolTipText( LOCTEXT( "WwiseItemToolTipText", "Choose a Wwise Item") )
			.OnClicked(FOnClicked::CreateSP(this, &FAkWwiseObjectDetailsStructCustomization::OnPickContent, ItemNameProperty.ToSharedRef()))
			.ContentPadding(2.0f)
			.ForegroundColor( FSlateColor::UseForeground() )
			.IsFocusable(false)
			[
				SNew(SImage)
				.Image(FAkAudioStyle::GetBrush("AudiokineticTools.Button_EllipsisIcon"))
				.ColorAndOpacity(FSlateColor::UseForeground())
			];

		HeaderRow.ValueContent()
		.MinDesiredWidth(125.0f)
		.MaxDesiredWidth(600.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.VAlign(VAlign_Center)
			[
				ItemNameProperty->CreatePropertyValueWidget()
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(FMargin(4.0f, 0.0f, 0.0f, 0.0f))
			.VAlign(VAlign_Center)
			[
				PickerWidget.ToSharedRef()
			]
	
		]
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		];

	}
}

void FAkWwiseObjectDetailsStructCustomization::CustomizeChildren( TSharedRef<IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils )
{
}

FReply FAkWwiseObjectDetailsStructCustomization::OnPickContent(TSharedRef<IPropertyHandle> PropertyHandle)
{
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(LOCTEXT("PropertyPickerWindowTitle", "Choose A Wwise Item"))
		.SizingRule(ESizingRule::UserSized)
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.ClientSize(FVector2D(350, 400));

	Window->SetContent(
		SNew(SBorder)
		[
			SAssignNew(WaapiPicker, SWaapiPicker)
			.FocusSearchBoxWhenOpened(true)
			.SelectionMode(ESelectionMode::Single)
			.OnSelectionChanged(this, &FAkWwiseObjectDetailsStructCustomization::TreeSelectionChanged)
		]
	);

	TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
	FSlateApplication::Get().AddWindowAsNativeChild(Window, RootWindow.ToSharedRef());
	return FReply::Handled();
}

void FAkWwiseObjectDetailsStructCustomization::TreeSelectionChanged(TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type SelectInfo)
{
	if (TreeItem.IsValid())
	{
		ItemNameProperty->SetValue(TreeItem->DisplayName);
		ItemIdProperty->SetValue(TreeItem->ItemId.ToString(EGuidFormats::DigitsWithHyphensInBraces));
		ItemPathProperty->SetValue(TreeItem->FolderPath);
	}
}
#undef LOCTEXT_NAMESPACE

#endif//WITH_EDITOR

