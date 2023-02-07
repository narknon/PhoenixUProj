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

#include "AkWaapiUMG/Components/AkCheckBox.h"
#include "AkAudioDevice.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Input/SCheckBox.h"
#include "Slate/SlateBrushAsset.h"
#include "AkWaapiUMG/Components/AkBoolPropertyToControlCustomization.h"
#include "AkWaapiUMG/Components/WwiseBoolPropertyDragDropOp.h"
#include "AkWaapiUtils.h"
#include "AkWaapiBlueprints/AkWaapiCalls.h"
#include "Async/Async.h"
#include "AkWaapiUMG/Components/WwiseUmgDragDropOp.h"
#include "WaapiPicker/SWaapiPicker.h"

#if WITH_EDITOR
#include "Editor.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#endif

#define LOCTEXT_NAMESPACE "AkWaapiUMG"

DEFINE_LOG_CATEGORY(LogAkCheckBoxUMG);

////////////////////////////////////////////////
// SCheckBoxDropHandler
////////////////////////////////////////////////

/** Drag-drop zone for adding a Wwise item or a bool property to the CheckBox */
class SCheckBoxDropHandler : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCheckBoxDropHandler) {}
		SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_EVENT(FOnDrop, OnDrop)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		OnDropDelegate = InArgs._OnDrop;

		this->ChildSlot
			[
				SNew(SBorder)
				[
					InArgs._Content.Widget
				]
			];
	}

	FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override
	{
		if (OnDropDelegate.IsBound())
		{
			return OnDropDelegate.Execute(MyGeometry, DragDropEvent);
		}
		return FReply::Handled();
	}

private:
	FOnDrop OnDropDelegate;
};

/////////////////////////////////////////////////////
// UAkCheckBox

UAkCheckBox::UAkCheckBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SCheckBox::FArguments SlateDefaults;
	WidgetStyle = *SlateDefaults._Style;

	CheckedState = ECheckBoxState::Unchecked;

	HorizontalAlignment = SlateDefaults._HAlign;

	IsFocusable = true;
}

void UAkCheckBox::BeginDestroy()
{
	if (SubscriptionIdNameChanged != 0)
	{
		bool isUnsubscribed;
		UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionIdNameChanged), isUnsubscribed);
		if (isUnsubscribed)
			SubscriptionIdNameChanged = 0;
	}
	if (SubscriptionId != 0)
	{
		bool isUnsubscribed;
		UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionId), isUnsubscribed);
		if (isUnsubscribed)
			SubscriptionId = 0;
	}

	Super::BeginDestroy();
}

void UAkCheckBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyCheckbox.Reset();
}

TSharedRef<SWidget> UAkCheckBox::RebuildWidget()
{
#if WITH_EDITOR
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomPropertyTypeLayout("AkBoolPropertyToControl", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FAkBoolPropertyToControlCustomization::MakeInstance));
	PropertyModule.NotifyCustomizationModuleChanged();
#endif//WITH_EDITOR

	MyCheckbox = SNew(SCheckBox)
		.OnCheckStateChanged(BIND_UOBJECT_DELEGATE(FOnCheckStateChanged, SlateOnCheckStateChangedCallback))
		.Style(&WidgetStyle)
		.HAlign(HorizontalAlignment)
		.IsFocusable(IsFocusable)
		;

	if (GetChildrenCount() > 0)
	{
		MyCheckbox->SetContent(GetContentSlot()->Content ? GetContentSlot()->Content->TakeWidget() : SNullWidget::NullWidget);
	}

	return
		SNew(SCheckBoxDropHandler)
		.OnDrop(FOnDrop::CreateUObject(this, &UAkCheckBox::OnDropHandler))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(FMargin(3.0f, 3.0f))
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				MyCheckbox.ToSharedRef()
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(5.0f, 0.0f, 0.0f, 0.0f)
				.HAlign(HAlign_Left)
				[
					SNew(STextBlock)
					.Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this, &UAkCheckBox::GetAkItemControlled)))
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(5.0f, 0.0f, 0.0f, 0.0f)
				.HAlign(HAlign_Left)
				[
					SNew(STextBlock)
					.Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this, &UAkCheckBox::GetAkBoolProperty)))
				]
			]
		];
}

void UAkCheckBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	MyCheckbox->SetStyle(&WidgetStyle);
	MyCheckbox->SetIsChecked(PROPERTY_BINDING(ECheckBoxState, CheckedState) );

	ItemToControl.ItemPath = ItemToControl.ItemPicked.ItemPath;

	FGuid ItemId;
	if (!ItemToControl.ItemPicked.ItemId.IsEmpty())
	{
		if(FGuid::ParseExact(ItemToControl.ItemPicked.ItemId, EGuidFormats::DigitsWithHyphensInBraces, ItemId))
		{
			SetAkItemId(ItemId);
		}
	}
	SetAkBoolProperty(ThePropertyToControl.ItemProperty);
}

void UAkCheckBox::SetAkItemControlled(const FString& Item)
{
	ItemControlled = Item;
}

FText UAkCheckBox::GetAkItemControlled()
{
	return FText::FromString(TEXT("Item : ") + ItemControlled);
}

void UAkCheckBox::SetAkItemId(const FGuid& ItemId)
{
	if (ItemId.IsValid())
	{
		IdItemToControl = ItemId.ToString(EGuidFormats::DigitsWithHyphensInBraces);
			
		TSharedPtr<FJsonObject> getResult;
		if (!SWaapiPicker::CallWaapiGetInfoFrom(WwiseWaapiHelper::ID, IdItemToControl, getResult, {}))
		{
			return;
		}
		TArray<TSharedPtr<FJsonValue>> StructJsonArray = getResult->GetArrayField(WwiseWaapiHelper::RETURN);
		if (StructJsonArray.Num() > 0)
		{
			const TSharedPtr<FJsonObject>& ItemInfoObj = StructJsonArray[0]->AsObject();
			SetAkItemControlled(ItemInfoObj->GetStringField(WwiseWaapiHelper::NAME));
		}

		/** UnSubscribe to object renamed to be notified from Wwise using WAAPI, so we can maintain the name of the item controlled up to date dynamically. */
		// Connect to Wwise Authoring on localhost.
		if (SubscriptionIdNameChanged != 0)
		{
			bool isUnsubscribed;
			UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionIdNameChanged), isUnsubscribed);
            if (isUnsubscribed)
                SubscriptionIdNameChanged = 0;
		}
		TSharedPtr<FJsonObject> outJsonResult;
		/** Subscribe to object renamed-created-deleted and removed to be notified from Wwise using WAAPI, so we can maintain the Wise picker up to date dynamically. */
		// Connect to Wwise Authoring on localhost.
		FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
		if (waapiClient)
		{
			auto wampEventCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
			{
				AsyncTask(ENamedThreads::GameThread, [this, in_UEJsonObject]
				{
					SetAkItemControlled(in_UEJsonObject->GetStringField(WwiseWaapiHelper::NEW_NAME));
				});
			});
			// Construct the options Json object : Getting parent infos.
			TSharedRef<FJsonObject> in_options = MakeShareable(new FJsonObject());
			// Subscribe to object renamed-created-deleted and removed notifications.
			waapiClient->Subscribe(ak::wwise::core::object::nameChanged, in_options, wampEventCallback, SubscriptionIdNameChanged, outJsonResult);
		}
		SynchronizePropertyWithWwise();
	}
}

const FGuid UAkCheckBox::GetAkItemId() const
{
	FGuid ItemId;
	if (!IdItemToControl.IsEmpty())
	{
		FGuid::ParseExact(IdItemToControl, EGuidFormats::DigitsWithHyphensInBraces, ItemId);
	}
	return ItemId;
}

void UAkCheckBox::SetAkBoolProperty(const FString& BoolProperty)
{
	BoolPropertyToControl = BoolProperty;
	SynchronizePropertyWithWwise();
}

const FString UAkCheckBox::GetAkProperty() const
{
	return BoolPropertyToControl;
}

FText UAkCheckBox::GetAkBoolProperty() const
{
	return FText::FromString(TEXT("Property : ") + GetAkProperty());
}

void UAkCheckBox::OnSlotAdded(UPanelSlot* InSlot)
{
	// Add the child to the live slot if it already exists
	if ( MyCheckbox.IsValid() )
	{
		MyCheckbox->SetContent(InSlot->Content ? InSlot->Content->TakeWidget() : SNullWidget::NullWidget);
	}
}

void UAkCheckBox::SynchronizePropertyWithWwise()
{
	if (!IdItemToControl.IsEmpty() && !BoolPropertyToControl.IsEmpty())
	{
		TSharedPtr<FJsonObject> ItemInfoResult;
		if (CallWappiGetPropertySate(IdItemToControl, BoolPropertyToControl, ItemInfoResult))
		{
			bool result = false;

			if (ItemInfoResult.Get()->TryGetBoolField(WwiseWaapiHelper::AT + BoolPropertyToControl, result))
			{
				SetIsChecked(result);
			}
		}

        if (SubscriptionId != 0)
        {
            bool isUnsubscribed;
            UAkWaapiCalls::Unsubscribe(FAkWaapiSubscriptionId(SubscriptionId), isUnsubscribed);
            if (isUnsubscribed)
                SubscriptionId = 0;
        }
		TSharedPtr<FJsonObject> outJsonResult;

		auto wampEventCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
		{
			bool result = false;
			if (in_UEJsonObject->TryGetBoolField(WwiseWaapiHelper::NEW, result))
			{
				SetIsChecked(result);
			}
		});
		SubscribeToPropertyStateChange(IdItemToControl, BoolPropertyToControl, wampEventCallback, SubscriptionId, outJsonResult);
	}
}

void UAkCheckBox::OnSlotRemoved(UPanelSlot* InSlot)
{
	// Remove the widget from the live slot if it exists.
	if ( MyCheckbox.IsValid() )
	{
		MyCheckbox->SetContent(SNullWidget::NullWidget);
	}
}

bool UAkCheckBox::IsPressed() const
{
	if ( MyCheckbox.IsValid() )
	{
		return MyCheckbox->IsPressed();
	}

	return false;
}

bool UAkCheckBox::IsChecked() const
{
	if ( MyCheckbox.IsValid() )
	{
		return MyCheckbox->IsChecked();
	}

	return ( CheckedState == ECheckBoxState::Checked );
}

ECheckBoxState UAkCheckBox::GetCheckedState() const
{
	if ( MyCheckbox.IsValid() )
	{
		return MyCheckbox->GetCheckedState();
	}

	return CheckedState;
}

void UAkCheckBox::SetIsChecked(bool InIsChecked)
{
	CheckedState = InIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
	if ( MyCheckbox.IsValid() )
	{
		MyCheckbox->SetIsChecked(PROPERTY_BINDING(ECheckBoxState, CheckedState));
	}
}

void UAkCheckBox::SetCheckedState(ECheckBoxState InCheckedState)
{
	CheckedState = InCheckedState;
	if ( MyCheckbox.IsValid() )
	{
		MyCheckbox->SetIsChecked(PROPERTY_BINDING(ECheckBoxState, CheckedState));
	}
}

void UAkCheckBox::SlateOnCheckStateChangedCallback(ECheckBoxState NewState)
{
	CheckedState = NewState;

	if (ItemControlled.IsEmpty() || BoolPropertyToControl.IsEmpty() || IdItemToControl.IsEmpty())
	{
		UE_LOG(LogAkCheckBoxUMG, Log, TEXT("No item or property to control"));
		return;
	}
	// Construct the arguments Json object : setting configs
	TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
	{
		args->SetStringField(WwiseWaapiHelper::OBJECT, IdItemToControl);
		args->SetStringField(WwiseWaapiHelper::PROPERTY, BoolPropertyToControl);
		args->SetBoolField(WwiseWaapiHelper::VALUE, IsChecked()); // this gives us a range of volume from [-96 to 12]
	}

	// Construct the options Json object;
	TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());

	// Connect to Wwise Authoring on localhost.
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
	if (waapiClient)
	{
		TSharedPtr<FJsonObject> outJsonResult;
		// Request data from Wwise using WAAPI
		if (waapiClient->Call(ak::wwise::core::object::setProperty, args, options, outJsonResult))
		{
		}
		else
		{
			UE_LOG(LogAkCheckBoxUMG, Log, TEXT("Call Failed"));
			return;
		}
	}
	else
	{
		UE_LOG(LogAkCheckBoxUMG, Log, TEXT("Unable to connect to localhost"));
		return;
	}

	//@TODO: Choosing to treat Undetermined as Checked
	const bool bWantsToBeChecked = NewState != ECheckBoxState::Unchecked;
	AkOnCheckStateChanged.Broadcast(bWantsToBeChecked);
}

FReply UAkCheckBox::OnDropHandler(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
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
					if (OnItemDropped.IsBound())
					{
						OnItemDropped.Broadcast(WwiseAssets[0]->ItemId);
					}
					else
					{
						SetAkItemId(WwiseAssets[0]->ItemId);
					}
					HandledState = FReply::Handled();
				}
			}
		}
		else if (Operation->IsOfType<FWwiseBoolPropertyDragDropOp>())
		{
			const auto& AssetDragDropOp = StaticCastSharedPtr<FWwiseBoolPropertyDragDropOp>(Operation);
			if (AssetDragDropOp.IsValid())
			{
				const auto& WwiseAssets = AssetDragDropOp->GetWiseProperties();
				if (WwiseAssets.Num() && WwiseAssets[0].IsValid())
				{
					if (OnPropertyDropped.IsBound())
					{
						OnPropertyDropped.Broadcast(*WwiseAssets[0].Get());
					}
					else
					{
						SetAkBoolProperty(*WwiseAssets[0].Get());
					}
					HandledState = FReply::Handled();
				}
			}
		}
	}
    return HandledState;
}


#if WITH_EDITOR

const FText UAkCheckBox::GetPaletteCategory()
{
	return LOCTEXT("Wwise", "Wwise");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
