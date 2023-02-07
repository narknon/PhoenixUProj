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
#include "WaapiPicker/SWaapiPicker.h"
#include "AkWwiseTree.h"
#include "AkWwiseTreeSelector.generated.h"


class IMenu;
class SButton;

/*------------------------------------------------------------------------------------
UAkSlider
------------------------------------------------------------------------------------*/

/**
* A widget that shows the Wwise tree items.
*/
UCLASS(config = Editor, defaultconfig)
class AKAUDIO_API UAkWwiseTreeSelector : public UWidget
{
	GENERATED_UCLASS_BODY()
public:
	typedef TSlateDelegates< TSharedPtr< FWwiseTreeItem > >::FOnSelectionChanged FOnSelectionChanged;

public:

	/** Called when the item selection changes. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnItemSelectionChanged OnSelectionChanged;

	/** Called when an item is dragged from the wwise tree. */
	UPROPERTY(BlueprintAssignable, Category = "Widget Event")
	FOnItemDragDetected OnItemDragged;

	// UWidget interface
	virtual void SynchronizeProperties() override;
	// End of UWidget interface

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
	/** Delegate used to handle the value of the item to be controlled */
	void TreeSelectionChanged(TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type SelectInfo);

	/** Delegate used to handle the drag detected action on the Wwise items. */
	FReply HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent);

	/** Delegate used to display the Waapi Picker */
	FReply HandleButtonClicked();

private:
	/** The widget to display the item name */
	TSharedPtr<STextBlock> ItemTextBlock;

	/** The Wwise tree used to pick an item */
	TSharedPtr<SWaapiPicker> WaapiPicker;

	/** The pick button widget */
	TSharedPtr<SButton> PickerButton;

	/** The pick button popup menu*/
	TSharedPtr<IMenu> PickerMenu;
};