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

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Layout/Margin.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "Widgets/SWidget.h"
#include "Components/ContentWidget.h"
#include "AkSlider.h"
#include "Widgets/SCompoundWidget.h"
#include "AkItemBoolProperties.h"
#include "AkCheckBox.generated.h"

class SCheckBox;
class USlateBrushAsset;
class USlateWidgetStyleAsset;

DECLARE_LOG_CATEGORY_EXTERN(LogAkCheckBoxUMG, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FAkOnCheckBoxComponentStateChanged, bool, bIsChecked );

/** A delegate type invoked when an item is being dragged. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWwiseItemDropDetected, FGuid, ItemDroppedID);

/** A delegate type invoked when a property is being dragged. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoolPropertyDropDetected, FString, PropertyDropped);

/**
 * The checkbox widget allows you to display a toggled state of 'unchecked', 'checked' and 
 * 'indeterminable.  You can use the checkbox for a classic checkbox, or as a toggle button,
 * or as radio buttons.
 * 
 * * Single Child
 * * Toggle
 */
UCLASS(config = Editor, defaultconfig)
class AKAUDIO_API UAkCheckBox : public UContentWidget, public SCompoundWidget
{
	GENERATED_UCLASS_BODY()

public:
	/** Whether the check box is currently in a checked state */
	UPROPERTY(EditAnywhere, Category=Appearance)
	ECheckBoxState CheckedState;

	/** A bindable delegate for the IsChecked. */
	UPROPERTY()
	FGetCheckBoxState CheckedStateDelegate;

public:
	/** The checkbox bar style */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style", meta=( DisplayName="Style" ))
	FCheckBoxStyle WidgetStyle;

	/** How the content of the toggle button should align within the given space */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance)
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	/** Sometimes a button should only be mouse-clickable and never keyboard focusable. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	bool IsFocusable;

	UPROPERTY(EditAnywhere, Category = "Audiokinetic|WAAPI|Checkbox", meta = (DisplayName = "Property to control"))
	FAkBoolPropertyToControl ThePropertyToControl;

	UPROPERTY(Config, VisibleAnywhere, Category = "Audiokinetic|WAAPI|Checkbox", meta = (DisplayName = "Item to control"))
	FAkWwiseItemToControl ItemToControl;

public:

	/** Called when the checked state has changed */
	UPROPERTY(BlueprintAssignable, Category="CheckBox|Event")
	FAkOnCheckBoxComponentStateChanged AkOnCheckStateChanged;

	/** Called when the item selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnWwiseItemDropDetected OnItemDropped;

	/** Called when the item selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnBoolPropertyDropDetected OnPropertyDropped;

public:

	/** Returns true if this button is currently pressed */
	UFUNCTION(BlueprintCallable, Category="Widget")
	bool IsPressed() const;
	
	/** Returns true if the checkbox is currently checked */
	UFUNCTION(BlueprintCallable, Category="Widget")
	bool IsChecked() const;

	/** @return the full current checked state. */
	UFUNCTION(BlueprintCallable, Category="Widget")
	ECheckBoxState GetCheckedState() const;

	/** Sets the checked state. */
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetIsChecked(bool InIsChecked);

	/** Sets the checked state. */
	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetCheckedState(ECheckBoxState InCheckedState);

	/** Set the item id to the new one.
	*  @param ItemId - value (new id) to set
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Checkbox", meta = (Keywords = "Set Item Id"))
	void SetAkItemId(const FGuid& ItemId);

	/** Returns the current item id.
	*
	*  @return an id as GUID.
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Checkbox", meta = (Keywords = "Get Item Id"))
	const FGuid GetAkItemId() const;

	/** Set the item property to the new one.
	*  @param ItemId - value (new id) to set
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Checkbox", meta = (Keywords = "Set Item Property"))
	void SetAkBoolProperty(const FString& ItemProperty);

	/** Returns the current item property.
	*
	*  @return a property as string.
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Checkbox", meta = (Keywords = "Get Item Property"))
	const FString GetAkProperty() const;


public:
	
	//~ Begin UWidget Interface
	virtual void SynchronizeProperties() override;
	//~ End UWidget Interface

	//~ Begin UVisual Interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UVisual Interface

	virtual void BeginDestroy() override;


#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	/**
	* Called when the user is dropping something onto a widget; terminates drag and drop.
	*
	* @param MyGeometry      The geometry of the widget receiving the event.
	* @param DragDropEvent   The drag and drop event.
	*
	* @return A reply that indicated whether this event was handled.
	*/
	FReply OnDropHandler(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent);

protected:

	// UPanelWidget
	virtual void OnSlotAdded(UPanelSlot* Slot) override;
	virtual void OnSlotRemoved(UPanelSlot* Slot) override;
	// End UPanelWidget

protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface

	void SlateOnCheckStateChangedCallback(ECheckBoxState NewState);

private:
	void SetAkItemControlled(const FString& Item);
	FText GetAkItemControlled();

	FText GetAkBoolProperty() const;

	void SynchronizePropertyWithWwise();

protected:
	TSharedPtr<SCheckBox> MyCheckbox;
	FString ItemControlled;
	FString IdItemToControl;
	FString BoolPropertyToControl;
	uint64 SubscriptionId = 0;
	uint64 SubscriptionIdNameChanged = 0;


	PROPERTY_BINDING_IMPLEMENTATION(ECheckBoxState, CheckedState);
	
};
