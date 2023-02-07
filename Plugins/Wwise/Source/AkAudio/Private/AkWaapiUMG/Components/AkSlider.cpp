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

#include "AkWaapiUMG/Components/AkSlider.h"
#include "AkAudioDevice.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "AkWaapiSlate/Widgets/Input/AkSSlider.h"
#include "UMGStyle.h"
#include "AkWaapiUMG/Components/AkWwiseObjectDetailsStructCustomization.h"
#include "AkWaapiUMG/Components/AkPropertyToControlCustomization.h"
#include "AkWaapiUMG/Components/WwiseUmgDragDropOp.h"
#include "AkWaapiUMG/Components/WwisePropertyDragDropOp.h"
#include "AkWaapiUtils.h"
#include "AkWaapiBlueprints/AkWaapiCalls.h"
#include "Widgets/Input/SSlider.h"
#include "Async/Async.h"

#if WITH_EDITOR
#include "Editor.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#endif

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkWaapiUMG"

/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/
static inline const float ComputeValue(const float inValue, const float inMaxValue, const float inMinValue)
{
	return (inValue - inMinValue) / (inMaxValue - inMinValue);
}
/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////
// UAkSlider

UAkSlider::UAkSlider(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Orientation = EOrientation::Orient_Horizontal;
	SliderBarColor = FLinearColor::White;
	SliderHandleColor = FLinearColor::White;
	StepSize = 0.01f;
	AkSSlider::FArguments Defaults;
	WidgetStyle = *Defaults._Style;
	IsFocusable = true;
	SubscriptionId = 0;
}

void UAkSlider::BeginDestroy()
{
    UnsubscribePropertyChangedCallback();
	Super::BeginDestroy();
}


TSharedRef<SWidget> UAkSlider::RebuildWidget()
{
#if WITH_EDITOR
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomPropertyTypeLayout("AkWwiseObjectDetails", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FAkWwiseObjectDetailsStructCustomization::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout("AkPropertyToControl", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FAkPropertyToControlCustomization::MakeInstance));
	PropertyModule.NotifyCustomizationModuleChanged();
#endif//WITH_EDITOR

	MyAkSlider = SNew(AkSSlider)
		.Style(&WidgetStyle)
		.IsFocusable(IsFocusable)
		.OnValueChanged(BIND_UOBJECT_DELEGATE(FOnFloatValueChanged, HandleOnValueChanged))
		.OnDrop(FOnDrop::CreateUObject(this, &UAkSlider::HandleDropped));

    SynchronizePropertyWithWwise();

#if WITH_EDITOR
	if (!IsRunningGame())
	{
		return CreateDesignerOutline(MyAkSlider.ToSharedRef());
	}
#endif
    return MyAkSlider.ToSharedRef();
}

void UAkSlider::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	TAttribute<float> ValueBinding = PROPERTY_BINDING(float, Value);
	
	if (MyAkSlider.IsValid())
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();

		MySlider->SetOrientation(Orientation);
		MySlider->SetSliderBarColor(SliderBarColor);
		MySlider->SetSliderHandleColor(SliderHandleColor);
		MySlider->SetValue(ValueBinding);
		MySlider->SetLocked(Locked);
		MySlider->SetIndentHandle(IndentHandle);
		MySlider->SetStepSize(StepSize);
		MyAkSlider->SetAkSliderRangeMin(minValue);
		MyAkSlider->SetAkSliderRangeMax(maxValue);

		ItemToControl.ItemPath = ItemToControl.ItemPicked.ItemPath;
		bool shouldSynchronize = false;
		if (!ThePropertyToControl.ItemProperty.IsEmpty() && (ThePropertyToControl.ItemProperty != MyAkSlider->GetAkSliderItemProperty()))
		{
			MyAkSlider->SetAkSliderItemProperty(ThePropertyToControl.ItemProperty);
			shouldSynchronize = true;
		}
		if (!ItemToControl.ItemPicked.ItemId.IsEmpty() && (ItemToControl.ItemPicked.ItemId != MyAkSlider->GetAkSliderItemId()))
		{
			MyAkSlider->SetAkSliderItemId(ItemToControl.ItemPicked.ItemId);
			shouldSynchronize = true;
		}
		if (shouldSynchronize)
			SynchronizePropertyWithWwise();
	}
}

void UAkSlider::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
    UnsubscribePropertyChangedCallback();
	MyAkSlider.Reset();
}

void UAkSlider::HandleOnValueChanged(float InValue)
{
	OnValueChanged.Broadcast(InValue);
}

float UAkSlider::GetValue() const
{
	if (MyAkSlider.IsValid() )
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			return MySlider->GetValue();
		}
	}
	return Value;
}

void UAkSlider::SetValue(float InValue)
{
	Value = InValue;
	if ( MyAkSlider.IsValid() )
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetValue(InValue);
		}
	}
}

void UAkSlider::SetIndentHandle(bool InIndentHandle)
{
	IndentHandle = InIndentHandle;
	if ( MyAkSlider.IsValid() )
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetIndentHandle(InIndentHandle);
		}
	}
}

void UAkSlider::SetLocked(bool InLocked)
{
	Locked = InLocked;
	if ( MyAkSlider.IsValid() )
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetLocked(InLocked);
		}
	}
}

void UAkSlider::SetStepSize(float InValue)
{
	StepSize = InValue;
	if (MyAkSlider.IsValid())
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetStepSize(InValue);
		}
	}
}

void UAkSlider::SetSliderHandleColor(FLinearColor InValue)
{
	SliderHandleColor = InValue;
	if (MyAkSlider.IsValid())
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetSliderHandleColor(InValue);
		}
	}
}

void UAkSlider::SetSliderBarColor(FLinearColor InValue)
{
	SliderBarColor = InValue;
	if (MyAkSlider.IsValid())
	{
		TSharedPtr<SSlider>  MySlider = MyAkSlider->GetAkSilder();
		if (MySlider.IsValid())
		{
			MySlider->SetSliderBarColor(InValue);
		}
	}
}

void UAkSlider::SetAkSliderItemId(const FGuid& ItemId)
{
	if (ItemId.IsValid())
	{
		MyAkSlider->SetAkSliderItemId(ItemId.ToString(EGuidFormats::DigitsWithHyphensInBraces));
		SynchronizePropertyWithWwise();
	}
}

const FGuid UAkSlider::GetAkSliderItemId() const
{
	FGuid ItemId = FGuid::NewGuid();
	FGuid::ParseExact(MyAkSlider->GetAkSliderItemId(), EGuidFormats::DigitsWithHyphensInBraces, ItemId);
	return ItemId;
}

void UAkSlider::SetAkSliderItemProperty(const FString& ItemProperty)
{
	if (!ItemProperty.IsEmpty())
	{
		MyAkSlider->SetAkSliderItemProperty(ItemProperty);
		SynchronizePropertyWithWwise();
	}
}

const FString UAkSlider::GetAkSliderItemProperty() const
{
	return MyAkSlider->GetAkSliderItemProperty();
}

void UAkSlider::SynchronizePropertyWithWwise()
{
	if (MyAkSlider.IsValid())
	{
		const FString& ItemId = MyAkSlider->GetAkSliderItemId();
		const FString& ItemProperty = MyAkSlider->GetAkSliderItemProperty();

		if (!ItemId.IsEmpty() && !ItemProperty.IsEmpty())
		{
			TSharedPtr<FJsonObject> ItemInfoResult;
			if (CallWappiGetPropertySate(ItemId, ItemProperty, ItemInfoResult) && MyAkSlider.IsValid())
			{
				double PropertyValue = 0.0;
				if (ItemInfoResult->TryGetNumberField(WwiseWaapiHelper::AT + ItemProperty, PropertyValue))
				{
					double maxRange = MyAkSlider->GetAkSliderRangeMax().GetValue();
					double minRange = MyAkSlider->GetAkSliderRangeMin().GetValue();
					if (PropertyValue > maxRange)
					{
						MyAkSlider->SetAkSliderRangeMax(PropertyValue);
						maxRange = PropertyValue;
					}
					if (PropertyValue < minRange)
					{
						MyAkSlider->SetAkSliderRangeMin(PropertyValue);
						minRange = PropertyValue;
					}
					const float newValue = ComputeValue(PropertyValue, maxRange, minRange);
					SetValue(newValue);
				}
			}

			if (SubscriptionId != 0)
			{
				bool isUnsubscribed;
				UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionId), isUnsubscribed);
			}
			TSharedPtr<FJsonObject> outJsonResult;

			auto wampEventCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
			{
				AsyncTask(ENamedThreads::GameThread, [this, id, in_UEJsonObject]
				{
					if (MyAkSlider.IsValid())
					{
						double PropertyValue = 0.0;
						if (in_UEJsonObject->TryGetNumberField(WwiseWaapiHelper::NEW, PropertyValue))
						{
							double maxRange = MyAkSlider->GetAkSliderRangeMax().GetValue();
							double minRange = MyAkSlider->GetAkSliderRangeMin().GetValue();
							if (PropertyValue > maxRange)
							{
								MyAkSlider->SetAkSliderRangeMax(PropertyValue);
								maxRange = PropertyValue;
							}
							else if (PropertyValue < minRange)
							{
								MyAkSlider->SetAkSliderRangeMin(PropertyValue);
								minRange = PropertyValue;
							}
							const float newValue = ComputeValue(PropertyValue, maxRange, minRange);
							SetValue(newValue);
						}
					}
				});
			});
			SubscribeToPropertyStateChange(ItemId, ItemProperty, wampEventCallback, SubscriptionId, outJsonResult);
		}
	}
}

void UAkSlider::UnsubscribePropertyChangedCallback()
{
    if (SubscriptionId != 0)
    {
        bool isUnsubscribed;
        UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionId), isUnsubscribed);
        if (isUnsubscribed)
            SubscriptionId = 0;
    }
}

FReply UAkSlider::HandleDropped(const FGeometry& DropZoneGeometry, const FDragDropEvent& DragDropEvent)
{		
	TSharedPtr<FDragDropOperation> Operation = DragDropEvent.GetOperation();
	if (Operation.IsValid())
	{
		if (OnItemDropped.IsBound() && Operation->IsOfType<FWwiseUmgDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FWwiseUmgDragDropOp>(Operation);
			if (AssetDragDropOp.IsValid())
			{
				const TArray<TSharedPtr<FWwiseTreeItem>>& WwiseAssets = AssetDragDropOp->GetWiseItems();
				if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
				{
					OnItemDropped.Broadcast(WwiseAssets[0]->ItemId);
					SynchronizePropertyWithWwise();
					return FReply::Handled();
				}
			}
		}
		else if (OnPropertyDropped.IsBound() && Operation->IsOfType<FWwisePropertyDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FWwisePropertyDragDropOp>(Operation);
			if (AssetDragDropOp.IsValid())
			{
				const TArray<TSharedPtr<FString>>& WwiseAssets = AssetDragDropOp->GetWiseProperties();
				if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
				{
					OnPropertyDropped.Broadcast(*WwiseAssets[0].Get());
					SynchronizePropertyWithWwise();
					return FReply::Handled();
				}
			}
		}

		SynchronizePropertyWithWwise();
	}
	return FReply::Unhandled();
}

#if WITH_EDITOR

const FText UAkSlider::GetPaletteCategory()
{
	return LOCTEXT("Wwise", "Wwise");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
