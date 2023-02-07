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

#include "Components/Widget.h"
#include "AkItemProperties.h"
#include "AkSlider.generated.h"

class AkSSlider;

/** A delegate type invoked when the value of the slider changes. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAkOnFloatValueChangedEvent, float, Value);

/** A delegate type invoked when an item is being dragged. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemDropDetected, FGuid, ItemDroppedID);

/** A delegate type invoked when a property is being dragged. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPropertyDropDetected, FString, PropertyDropped);

/**
* Structure for Wwise item details.
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWwiseObjectDetails
{
	GENERATED_USTRUCT_BODY()

	/**
	* The name of the item to control
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=ItemName, meta = (DisplayName = "Name"))
	FString ItemName;
	
	/**
	* The id of the item to control
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ItemPath, meta = (DisplayName = "Path"))
	FString ItemPath;

	/**
	* The id of the item to control
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category =ItemId, meta = (DisplayName = "Id"))
	FString ItemId;
};

/**
* Structure for Wwise items that are displayed in the UMG.
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWwiseItemToControl //: public UObject
{
	GENERATED_USTRUCT_BODY()

	/**
	* The item to control
	*/
	UPROPERTY(VisibleAnywhere, Category= ItemPicked, meta = (DisplayName = "Name"))
	FAkWwiseObjectDetails ItemPicked;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=ItemPath, meta = (DisplayName = "Path"))
	FString ItemPath;
};

/*------------------------------------------------------------------------------------
UAkSlider
------------------------------------------------------------------------------------*/

/**
 * A simple widget that shows a sliding bar with a handle that allows you to control the value between 0..1.
 *
 * * No Children
 */
UCLASS(config = Editor, defaultconfig)
class AKAUDIO_API UAkSlider : public UWidget
{
	GENERATED_UCLASS_BODY()

public:
	/** The volume value to display. */
	UPROPERTY(EditAnywhere, Category=Appearance, meta=(ClampMin = "0", ClampMax = "1", UIMin = "0", UIMax = "1"))
	float Value;

	/** A bindable delegate to allow logic to drive the value of the widget */
	UPROPERTY()
	FGetFloat ValueDelegate;

public:
	
	/** The progress bar style */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style", meta=( DisplayName="Style" ))
	FSliderStyle WidgetStyle;

	/** The slider's orientation. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance)
	TEnumAsByte<EOrientation> Orientation;

	/** The color to draw the slider bar in. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance)
	FLinearColor SliderBarColor;

	/** The color to draw the slider handle in. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance)
	FLinearColor SliderHandleColor;

	/** Whether the slidable area should be indented to fit the handle. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance, AdvancedDisplay)
	bool IndentHandle;

	/** Whether the handle is interactive or fixed. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance, AdvancedDisplay)
	bool Locked;

	/** The amount to adjust the value by, when using a controller or keyboard */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Appearance, meta=( ClampMin="0", ClampMax="1", UIMin="0", UIMax="1"))
	float StepSize;

	/** Should the slider be focusable? */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	bool IsFocusable;

	UPROPERTY(VisibleAnywhere, Category = "Audiokinetic|WAAPI|Slider", meta = (DisplayName = "Property to control"))
	FAkPropertyToControl ThePropertyToControl;

	UPROPERTY(Config, VisibleAnywhere, Category = "Audiokinetic|WAAPI|Slider", meta = (DisplayName = "Item to control"))
	FAkWwiseItemToControl ItemToControl;

	/** Called when the value is changed by slider or typing. */
	UPROPERTY(BlueprintAssignable, Category="Widget Event")
	FAkOnFloatValueChangedEvent OnValueChanged;

	/** Called when the item selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnItemDropDetected OnItemDropped;

	/** Called when the item selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnPropertyDropDetected OnPropertyDropped;

public:

	/** Gets the current value of the slider. */
	UFUNCTION(BlueprintCallable, Category="Behavior")
	float GetValue() const;

	/** Sets the current value of the slider. */
	UFUNCTION(BlueprintCallable, Category="Behavior")
	void SetValue(float InValue);

	/** Sets if the slidable area should be indented to fit the handle */
	UFUNCTION(BlueprintCallable, Category="Behavior")
	void SetIndentHandle(bool InValue);

	/** Sets the handle to be interactive or fixed */
	UFUNCTION(BlueprintCallable, Category="Behavior")
	void SetLocked(bool InValue);

	/** Sets the amount to adjust the value by, when using a controller or keyboard */
	UFUNCTION(BlueprintCallable, Category="Behavior")
	void SetStepSize(float InValue);

	/** Sets the color of the slider bar */
	UFUNCTION(BlueprintCallable, Category="Appearance")
	void SetSliderBarColor(FLinearColor InValue);

	/** Sets the color of the handle bar */
	UFUNCTION(BlueprintCallable, Category="Appearance")
	void SetSliderHandleColor(FLinearColor InValue);
	
	/** Set the item id to the new one.
	*  @param ItemId - value (new id) to set
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Slider", meta = (Keywords = "Set Item Id"))
	void SetAkSliderItemId(const FGuid& ItemId);

	/** Returns the current item id.
	*
	*  @return an id as GUID.
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Slider", meta = (Keywords = "Get Item Id"))
	const FGuid GetAkSliderItemId() const;

	/** Set the item property to the new one.
	*  @param ItemId - value (new id) to set
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Slider", meta = (Keywords = "Set Item Property"))
	void SetAkSliderItemProperty(const FString& ItemProperty);

	/** Returns the current item property.
	*
	*  @return a property as string.
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WAAPI|Slider", meta = (Keywords = "Get Item Property"))
	const FString GetAkSliderItemProperty() const;

	// UWidget interface
	virtual void SynchronizeProperties() override;
	// End of UWidget interface

	// UVisual interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	// End of UVisual interface

	virtual void BeginDestroy() override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	uint64 SubscriptionId;

	/** Native Slate Widget */
	TSharedPtr<AkSSlider> MyAkSlider;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface

	void HandleOnValueChanged(float InValue);

	/** Handles dropping of a wwise item onto the slider */
	FReply HandleDropped(const FGeometry& DropZoneGeometry, const FDragDropEvent& DragDropEvent);

	PROPERTY_BINDING_IMPLEMENTATION(float, Value);
private:
	void SynchronizePropertyWithWwise();
    void UnsubscribePropertyChangedCallback();

    /** The minimum value the the slider could take */
    float minValue;

    /** The minimum value the the slider could take */
    float maxValue;

};
