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

#include "AkWaapiUMG/Components/AkItemProperties.h"
#include "AkAudioDevice.h"
#include "Widgets/Input/SButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "AkWaapiUMG/Components/WwisePropertyDragDropOp.h"
#include "AkWaapiSlate/Widgets/Input/AkSSlider.h"
#include "AkAudioStyle.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkWaapiUMG"

/*------------------------------------------------------------------------------------
UAkItemPropertiesConv
------------------------------------------------------------------------------------*/

UAkItemPropertiesConv::UAkItemPropertiesConv(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Property initialization
}

FString UAkItemPropertiesConv::Conv_FAkPropertyToControlToString(const FAkPropertyToControl& INAkPropertyToControl)
{
	return INAkPropertyToControl.ItemProperty;
}

FText UAkItemPropertiesConv::Conv_FAkPropertyToControlToText(const FAkPropertyToControl& INAkPropertyToControl)
{
	return FText::FromString(*INAkPropertyToControl.ItemProperty);
}

/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////
// UAkItemProperties

UAkItemProperties::UAkItemProperties(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AkSSlider::FArguments Defaults;
}

TSharedRef<SWidget> UAkItemProperties::RebuildWidget()
{
    bool autoFocus = GetWorld()->WorldType != EWorldType::Game &&
                     GetWorld()->WorldType != EWorldType::PIE &&
                     GetWorld()->WorldType != EWorldType::GamePreview;
	return
	SNew(SBorder)
	.BorderImage(FAkAudioStyle::GetBrush("AudiokineticTools.GroupBorder"))
	.Padding(FMargin(0.0f, 3.0f))
	.BorderBackgroundColor(FLinearColor(.6, .6, .6, 1.0f))
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(FMargin(10.0f, 0.0f, 0.0f, 0.0f))
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SAssignNew(PropertyTextBlock, STextBlock)
				.IsEnabled(true)
				.ToolTipText(LOCTEXT("editable_Tooltip", "Property Name"))
				.MinDesiredWidth(300.f)
				.Text(FText::FromString(TEXT("Choose a property")))
			]
		]
		+ SVerticalBox::Slot()
		[
			SAssignNew(WwiseProperties, SAkItemProperties)
			.FocusSearchBoxWhenOpened(autoFocus)
			.SelectionMode(ESelectionMode::Single)
			.OnSelectionChanged(FOnSelectionChanged::CreateUObject(this, &UAkItemProperties::PropertySelectionChanged))
			.OnDragDetected(FOnDragDetected::CreateUObject(this, &UAkItemProperties::HandleOnDragDetected))
		]
	];
}

void UAkItemProperties::PropertySelectionChanged(TSharedPtr< FString > PropertySelected, ESelectInfo::Type SelectInfo)
{
	if (PropertySelected.IsValid())
	{
		const auto& PropertyString = *PropertySelected.Get();
		PropertyTextBlock->SetText(FText::FromString(PropertyString));

		if (OnSelectionChanged.IsBound())
		{
			OnSelectionChanged.Broadcast(PropertyString);
		}
	}
}

FReply UAkItemProperties::HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && WwiseProperties.IsValid())
	{
		const TArray<TSharedPtr<FString>>& ProperySelected = WwiseProperties->GetSelectedProperties();
		if (ProperySelected.Num() == 1)
		{		
			if(OnPropertyDragged.IsBound())
			{
				OnPropertyDragged.Broadcast(*ProperySelected[0].Get());
			}
			TSharedRef<FWwisePropertyDragDropOp> Operation = FWwisePropertyDragDropOp::New(ProperySelected);
			return FReply::Handled().BeginDragDrop(Operation);
		}
	}
	return FReply::Unhandled();
}

FString UAkItemProperties::GetSelectedProperty() const
{
	return *WwiseProperties->GetSelectedProperties()[0];
}

FString UAkItemProperties::GetSearchText() const
{
	return WwiseProperties->GetSearchText();
}

void UAkItemProperties::SetSearchText(const FString& newText)
{
	WwiseProperties->SetSearchText(newText);
}

void UAkItemProperties::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	PropertyTextBlock.Reset();
	WwiseProperties.Reset();
}

#if WITH_EDITOR

const FText UAkItemProperties::GetPaletteCategory()
{
	return LOCTEXT("Wwise", "Wwise");
}

#endif
//
/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
