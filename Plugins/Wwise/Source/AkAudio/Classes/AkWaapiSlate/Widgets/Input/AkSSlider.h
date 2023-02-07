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
#include "Misc/Attribute.h"
#include "Input/Reply.h"
#include "Styling/SlateWidgetStyleAsset.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "Styling/CoreStyle.h"
#include "Framework/SlateDelegates.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkAudioSliderUMG, Log, All);

class SSlider;

/**
 * A Slate slider control is a linear scale and draggable handle.
 */
class AKAUDIO_API AkSSlider
	: public SCompoundWidget
{
public:
	 
	SLATE_BEGIN_ARGS(AkSSlider)
		: _Style(&FCoreStyle::Get().GetWidgetStyle<FSliderStyle>("Slider"))
		, _IsFocusable(true)
		, _OnValueChanged()
		, _OnDrop()
	{}
	/** The style used to draw the slider. */
	SLATE_STYLE_ARGUMENT(FSliderStyle, Style)

	/** Sometimes a slider should only be mouse-clickable and never keyboard focusable. */
	SLATE_ARGUMENT(bool, IsFocusable)

	/** Called when the value is changed by the slider. */
	SLATE_EVENT(FOnFloatValueChanged, OnValueChanged)

	/** Called when an item is dropped into the slider. */
	SLATE_EVENT(FOnDrop, OnDrop)

	/** Slot for this designers content (optional) */
	SLATE_DEFAULT_SLOT(FArguments, Content)

	SLATE_END_ARGS()

	/**
	 * Construct the widget.
	 * 
	 * @param InDeclaration A declaration from which to construct the widget.
	 */
	void Construct( const AkSSlider::FArguments& InDeclaration );

	TSharedPtr<SSlider> GetAkSilder() const;

	/**
	* Getter to access the current value of the slider
	*
	* @Return the current value of the slider
	*/
	TOptional<double> GetAkSliderValue() const;
	
	/**
	* Getter to access the current property controlled by the slider
	*
	* @Return the current property of the slider
	*/
	FText GetAkSliderProperty() const;

	/**
	* Getter to access the name of the current item controlled by the slider
	*
	* @Return the item name of the item controlled
	*/
	FText GetAkSliderItemControlled() const;

	void SetAkSliderItemProperty(const FString& ItemProperty);
	const FString& GetAkSliderItemProperty() const;

	void SetAkSliderItemId(const FString& ItemId);
	const FString& GetAkSliderItemId() const;

	/**
	* Setters to update the min and max range of a property
	*/
	void SetAkSliderRangeMin(const double in_NewValue);
	void SetAkSliderRangeMax(const double in_NewValue);

	/**
	* Getters to access the min and max range of a property
	*/
	TOptional<double> GetAkSliderRangeMin() const;
    TOptional<double> GetAkSliderRangeMax() const;


	/**
	* Called when the user is dropping something onto a widget; terminates drag and drop.
	*
	* @param MyGeometry      The geometry of the widget receiving the event.
	* @param DragDropEvent   The drag and drop event.
	*
	* @return A reply that indicated whether this event was handled.
	*/
	FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;

	/**
	* Called when the user changes the value of the slider.
	*
	* @param newValue      The new value to set for the slider.
	*/
	void OnValueCommitted(double newValue, ETextCommit::Type Commit);

private:

	/** Holds the scrubber slider. */
	TSharedPtr<SSlider> AkScrubberSSlider;

	/** holds the current value of the slider*/
	FText AkSliderValue;

	/** holds the property of the item to be controlled*/
	FString AkSliderItemProperty;

	/** holds the ID of the current item to control*/
	FString AkSliderItemId;
	
	/** holds the name of the current item to control*/
	FString ItemControlled;

	/** Executed when an item is dropped onto the slider*/
	FOnDrop OnDropDelegate;

	/** The max range of the property controlled by the current slider*/
	double UIMaxValue;
	
	/** The min range of the property controlled by the current slider*/
	double UIMinValue;

private:

	/** Callback for changing the value of the 'Position' slider. */
	void HandleAkSliderValueChanged(float NewValue);
protected:
	inline void UpdateRange();
};
