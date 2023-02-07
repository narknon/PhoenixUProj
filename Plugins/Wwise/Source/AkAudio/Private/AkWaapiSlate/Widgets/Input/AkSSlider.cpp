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

#include "AkWaapiSlate/Widgets/Input/AkSSlider.h"
#include "AkAudioDevice.h"
#include "Rendering/DrawElements.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Text/STextBlock.h"
#include "WaapiPicker/SWaapiPicker.h"
#include "AkWaapiUMG/Components/WwiseUmgDragDropOp.h"
#include "AkWaapiUMG/Components/WwisePropertyDragDropOp.h"
#include "AkWaapiUtils.h"
#include "Widgets/Input/SNumericEntryBox.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/

#define LOCTEXT_NAMESPACE "AkWaapiUMG"

DEFINE_LOG_CATEGORY(LogAkAudioSliderUMG);
/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/

void AkSSlider::Construct(const AkSSlider::FArguments& InDeclaration)
{
	check(InDeclaration._Style);

	OnDropDelegate = InDeclaration._OnDrop;

	this->ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(this, &AkSSlider::GetAkSliderItemControlled)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(this, &AkSSlider::GetAkSliderProperty)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<double>)
					.Value(this, &AkSSlider::GetAkSliderValue)
					.MinValue(this, &AkSSlider::GetAkSliderRangeMin)
					.MinSliderValue(this, &AkSSlider::GetAkSliderRangeMin)
					.MaxValue(this, &AkSSlider::GetAkSliderRangeMax)
					.MaxSliderValue(this, &AkSSlider::GetAkSliderRangeMax)
					.OnValueCommitted(this, &AkSSlider::OnValueCommitted)
					
				]
			]
			+ SVerticalBox::Slot()
			[
				SAssignNew(AkScrubberSSlider, SSlider)
				.OnValueChanged(this, &AkSSlider::HandleAkSliderValueChanged)
				.Style(InDeclaration._Style)
			]
		];
}

TSharedPtr<SSlider> AkSSlider::GetAkSilder() const
{
	return AkScrubberSSlider;
}

TOptional<double> AkSSlider::GetAkSliderValue() const
{
    if (AkScrubberSSlider.IsValid())
	    return AkScrubberSSlider->GetValue()*(UIMaxValue - UIMinValue) + UIMinValue;
    return 0.0f;
}

FText AkSSlider::GetAkSliderProperty() const
{
	return FText::FromString(TEXT("Property : ") + AkSliderItemProperty);
}

FText AkSSlider::GetAkSliderItemControlled() const
{
	return FText::FromString(TEXT("Item : ") + ItemControlled);
}

void AkSSlider::HandleAkSliderValueChanged(float NewValue)
{
	if (AkSliderItemId.IsEmpty() || AkSliderItemProperty.IsEmpty())
	{
		UE_LOG(LogAkAudioSliderUMG, Log, TEXT("No item or property to control"));
		return;
	}
	// Construct the arguments Json object"
	TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
	{
		args->SetStringField(WwiseWaapiHelper::OBJECT, AkSliderItemId);
		args->SetStringField(WwiseWaapiHelper::PROPERTY, AkSliderItemProperty);

		args->SetNumberField(WwiseWaapiHelper::VALUE, NewValue*(UIMaxValue - UIMinValue) + UIMinValue); // e.i. This gives us a range of volume from [-96 to 12] for the volume property
	}

	// Construct the options Json object;
	TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());

	// Connect to Wwise Authoring on localhost.
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
    if (waapiClient == nullptr)
    {
        return;
    }
	TSharedPtr<FJsonObject> outJsonResult;
	// Request data from Wwise using WAAPI
	if (!waapiClient->Call(ak::wwise::core::object::setProperty, args, options, outJsonResult))
	{
		UE_LOG(LogAkAudioSliderUMG, Log, TEXT("Failed to set property %s on AKSSlider"), *AkSliderItemProperty);
	}
}

FReply AkSSlider::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	FReply HandledState = FReply::Unhandled();
	TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
	if (Operation.IsValid())
	{
		if (Operation->IsOfType<FWwiseUmgDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FWwiseUmgDragDropOp>(Operation);
			if (AssetDragDropOp.IsValid())
			{
				const auto& WwiseAssets = AssetDragDropOp->GetWiseItems();
				if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
				{
					SetAkSliderItemId(WwiseAssets[0]->ItemId.ToString(EGuidFormats::DigitsWithHyphensInBraces));
				}
				if (OnDropDelegate.IsBound())
				{
					HandledState = OnDropDelegate.Execute(MyGeometry, DragDropEvent);
				}

				if (!HandledState.IsEventHandled())
				{
					if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
					{
						HandledState = FReply::Handled();
					}
				}
			}
		}
		else if (Operation->IsOfType<FWwisePropertyDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FWwisePropertyDragDropOp>(Operation);
			if (AssetDragDropOp.IsValid())
			{
				const auto& WwiseAssets = AssetDragDropOp->GetWiseProperties();
				if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
				{
					SetAkSliderItemProperty(*WwiseAssets[0].Get());
				}
				if (OnDropDelegate.IsBound())
				{
					HandledState = OnDropDelegate.Execute(MyGeometry, DragDropEvent);
				}

				if (!HandledState.IsEventHandled())
				{
					if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
					{
						HandledState = FReply::Handled();
					}
				}
			}
		}
	}
	return HandledState;
}

void AkSSlider::SetAkSliderItemProperty(const FString& ItemProperty)
{
	if (!ItemProperty.IsEmpty() && (AkSliderItemProperty != ItemProperty))
	{
		AkSliderItemProperty = ItemProperty;
		UpdateRange();
	}
}

const FString& AkSSlider::GetAkSliderItemProperty() const
{
	return AkSliderItemProperty;
}

void AkSSlider::SetAkSliderItemId(const FString& ItemId)
{
	if (!ItemId.IsEmpty() && (AkSliderItemId != ItemId))
	{
		AkSliderItemId = ItemId;
		TSharedPtr<FJsonObject> getResult;
		FString itemName = TEXT("");
		if (SWaapiPicker::CallWaapiGetInfoFrom(WwiseWaapiHelper::ID, AkSliderItemId, getResult, {}))
		{
			// Recover the information from the Json object getResult and use it to get the item name.
			TArray<TSharedPtr<FJsonValue>> StructJsonArray = getResult->GetArrayField(WwiseWaapiHelper::RETURN);
			if (StructJsonArray.Num() > 0)
			{
				const TSharedPtr<FJsonObject>& ItemInfoObj = StructJsonArray[0]->AsObject();
				ItemControlled = ItemInfoObj->GetStringField(WwiseWaapiHelper::NAME);
			}
		}
		UpdateRange();
	}
}

inline void AkSSlider::UpdateRange()
{
	if(AkSliderItemId.IsEmpty())
		return;

	// Construct the arguments Json object.
	TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
	args->SetStringField(WwiseWaapiHelper::OBJECT, AkSliderItemId);
	args->SetStringField(WwiseWaapiHelper::PROPERTY, AkSliderItemProperty);

	// Construct the options Json object.
	TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());

	TSharedPtr<FJsonObject> outJsonResult;
	// Connect to Wwise Authoring on localhost.
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
	if (waapiClient)
	{
		// Request data from Wwise using WAAPI
		if (waapiClient->Call(ak::wwise::core::object::getPropertyInfo, args, options, outJsonResult))
		{
			// Recover the information from the Json object outJsonResult and use it to get the property state.
			if (outJsonResult->HasField(WwiseWaapiHelper::UI))
			{
				TSharedPtr<FJsonObject> uiLimit = outJsonResult->GetObjectField(WwiseWaapiHelper::UI)->GetObjectField(WwiseWaapiHelper::VALUE);
                UIMinValue = uiLimit->GetNumberField(WwiseWaapiHelper::MIN);
                UIMaxValue = uiLimit->GetNumberField(WwiseWaapiHelper::MAX);
			}
		}
	}
}

const FString& AkSSlider::GetAkSliderItemId() const
{
	return AkSliderItemId;
}

void AkSSlider::SetAkSliderRangeMax(const double in_NewValue)
{
	UIMaxValue = in_NewValue;
}


void AkSSlider::SetAkSliderRangeMin(const double in_NewValue)
{
	UIMinValue = in_NewValue;
}



TOptional<double> AkSSlider::GetAkSliderRangeMin() const
{
    return UIMinValue;
}
TOptional<double> AkSSlider::GetAkSliderRangeMax() const 
{
    return UIMaxValue;
}

void AkSSlider::OnValueCommitted(double InNewValue, ETextCommit::Type Commit)
{
	if (AkSliderItemProperty.IsEmpty() || InNewValue > UIMaxValue || InNewValue < UIMinValue)
	{
		return;
	}

	const float newValue = (InNewValue - UIMinValue) / (UIMaxValue - UIMinValue);
    if (AkScrubberSSlider.IsValid())
	    AkScrubberSSlider->SetValue(newValue);
	HandleAkSliderValueChanged(newValue);
}

#undef LOCTEXT_NAMESPACE