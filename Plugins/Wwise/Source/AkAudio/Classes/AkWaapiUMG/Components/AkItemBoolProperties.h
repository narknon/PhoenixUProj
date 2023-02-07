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
#include "SAkItemBoolProperties.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkItemBoolProperties.generated.h"


class IMenu;
class SButton;

/** A delegate type invoked when a selection changes somewhere. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemBoolPropertySelectionChanged, FString, PropertySelected);

/** A delegate type invoked when a property is being dragged. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemBoolPropertyDragDetected, FString, PropertyDragged);

/*------------------------------------------------------------------------------------
FAkBoolPropertyToControl
------------------------------------------------------------------------------------*/

/**
* Structure for property to be controlled by the UI.
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkBoolPropertyToControl
{
	GENERATED_USTRUCT_BODY()

		/**
		* The name of the item to control
		*/
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ItemProperty, meta = (DisplayName = "Property"))
		FString ItemProperty;
};

/*------------------------------------------------------------------------------------
UAkItemBoolPropertiesConv
------------------------------------------------------------------------------------*/

UCLASS()
class AKAUDIO_API UAkItemBoolPropertiesConv : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/** Converts an AkBoolPropertyToControl value to a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (FAkBoolPropertyToControl)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_FAkBoolPropertyToControlToString(const FAkBoolPropertyToControl& INAkBoolPropertyToControl);

	/** Converts an AkBoolPropertyToControl value to a localizable text */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToText (FAkBoolPropertyToControl)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|Text")
	static FText Conv_FAkBoolPropertyToControlToText(const FAkBoolPropertyToControl& INAkBoolPropertyToControl);
};

/*------------------------------------------------------------------------------------
UAkItemBoolProperties
------------------------------------------------------------------------------------*/

/**
* A widget that shows the Wwise properties list.
*/
UCLASS(config = Editor, defaultconfig)
class AKAUDIO_API UAkItemBoolProperties : public UWidget
{
	GENERATED_UCLASS_BODY()
public:
	typedef TSlateDelegates< TSharedPtr< FString > >::FOnSelectionChanged FOnSelectionChanged;

public:	

	/** Called when the property selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnItemBoolPropertySelectionChanged OnSelectionChanged;

	/** Called when a property is dragged from the property list. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnItemBoolPropertyDragDetected OnPropertyDragged;

	/** Returns all properties currently selected in the Wwise properties list */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic")
	FString GetSelectedProperty() const;

	/** returns the current text of the searchBox */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic")
	FString GetSearchText() const;

	/** sets the current text of the searchBox */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic")
	void SetSearchText(const FString& newText);

	// UVisual interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	// End of UVisual interface

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface

private:
	/** Delegate used to handle the value of the property to be controlled */
	void PropertySelectionChanged(TSharedPtr< FString > PropertySelected, ESelectInfo::Type SelectInfo);

	/** Delegate used to handle the drag detected action on the items properties. */
	FReply HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent);
private:
	/** The widget to display the property name */
	TSharedPtr<STextBlock> PropertyTextBlock;

	/** The Wwise list used to pick an item property */
	TSharedPtr<SAkItemBoolProperties> WwiseProperties;
};