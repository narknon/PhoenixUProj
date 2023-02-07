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
includes.
------------------------------------------------------------------------------------*/

#include "AkWaapiUMG/Components/AkWwiseTreeSelector.h"
#include "AkAudioDevice.h"
#include "Widgets/Input/SButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Docking/TabManager.h"
#include "Framework/Application/SlateApplication.h"
#include "AkWaapiUMG/Components/WwiseUmgDragDropOp.h"
#include "AkWaapiSlate/Widgets/Input/AkSSlider.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkWaapiUMG"

/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////
// UAkWwiseTreeSelector

UAkWwiseTreeSelector::UAkWwiseTreeSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AkSSlider::FArguments Defaults;
}

TSharedRef<SWidget> UAkWwiseTreeSelector::RebuildWidget()
{
	TSharedPtr<SWidget> PickerWidget = nullptr;

	PickerWidget = SAssignNew(PickerButton, SButton)
		.ButtonStyle(FAkAudioStyle::Get(), "AudiokineticTools.HoverHintOnly")
		.ToolTipText(LOCTEXT("WwiseItemToolTipText", "Choose a Wwise Item"))
		.OnClicked(FOnClicked::CreateUObject(this, &UAkWwiseTreeSelector::HandleButtonClicked))
		.ContentPadding(2.0f)
		.ForegroundColor(FSlateColor::UseForeground())
		.IsFocusable(true)
		[
			SNew(SImage)
			.Image(FAkAudioStyle::GetBrush("AudiokineticTools.Button_EllipsisIcon"))
			.ColorAndOpacity(FSlateColor::UseForeground())
		];

	return
		SNew(SBorder)
		.BorderImage(FAkAudioStyle::GetBrush("AudiokineticTools.GroupBorder"))
		.Padding(FMargin(0.0f, 3.0f))
		.BorderBackgroundColor(FLinearColor(.6, .6, .6, 1.0f))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(FMargin(10.0f, 0.0f, 0.0f, 0.0f))
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SAssignNew(ItemTextBlock, STextBlock)
				.IsEnabled(true)
				.ToolTipText(LOCTEXT("editable_Tooltip", "Item Name"))
				.MinDesiredWidth(300.f)
				.Text(FText::FromString(TEXT("Choose an item from the Wwise tree")))
			]
			+ SHorizontalBox::Slot()
				.Padding(FMargin(0.0f, 0.0f, 10.0f, 0.0f))
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Right)
				[
					PickerWidget.ToSharedRef()
				]
		];
}

FReply UAkWwiseTreeSelector::HandleButtonClicked()
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
			.RestrictContextMenu(true)
			.FocusSearchBoxWhenOpened(true)
			.SelectionMode(ESelectionMode::Single)
			.OnSelectionChanged(FOnSelectionChanged::CreateUObject(this, &UAkWwiseTreeSelector::TreeSelectionChanged))
			.OnDragDetected(FOnDragDetected::CreateUObject(this, &UAkWwiseTreeSelector::HandleOnDragDetected))
		]
	);
#if WITH_EDITOR
	TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
	FSlateApplication::Get().AddWindowAsNativeChild(Window, RootWindow.ToSharedRef());
#endif//WITH_EDITOR
	return FReply::Handled();
}

void UAkWwiseTreeSelector::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

void UAkWwiseTreeSelector::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	ItemTextBlock.Reset();
	WaapiPicker.Reset();
	PickerButton.Reset();
	PickerMenu.Reset();
}

void UAkWwiseTreeSelector::TreeSelectionChanged(TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type SelectInfo)
{
	if (TreeItem.IsValid())
	{
		ItemTextBlock->SetText(FText::FromString(TreeItem->DisplayName));

		if (OnSelectionChanged.IsBound())
		{
			OnSelectionChanged.Broadcast(TreeItem->ItemId);
		}
	}
}

FReply UAkWwiseTreeSelector::HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && WaapiPicker.IsValid())
	{
		const TArray<TSharedPtr<FWwiseTreeItem>>& ItemsSelected = WaapiPicker->GetSelectedItems();
		if (ItemsSelected.Num() == 1)
		{
			if (OnItemDragged.IsBound())
			{
				OnItemDragged.Broadcast(ItemsSelected[0]->ItemId, ItemsSelected[0]->DisplayName);
			}
			return FReply::Handled().BeginDragDrop(FWwiseUmgDragDropOp::New(ItemsSelected));
		}
	}
	return FReply::Unhandled();
}

#if WITH_EDITOR

const FText UAkWwiseTreeSelector::GetPaletteCategory()
{
	return LOCTEXT("Wwise", "Wwise");
}

#endif
//
/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
