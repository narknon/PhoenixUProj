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
	SWaapiPickerRow.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
	SWaapiPickerRow
------------------------------------------------------------------------------------*/
#include "WwiseTreeItem.h"
#include "AkWaapiClient.h"
#include "Dom/JsonObject.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "Widgets/SCompoundWidget.h"

/** A single item in the Wwise tree. */
class AKAUDIO_API SWaapiPickerRow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWaapiPickerRow)
		: _WaapiPickerItem(TSharedPtr<FWwiseTreeItem>())
		, _ParentWidget()
	{}

		/** Data that represents the WwiseItem */
		SLATE_ARGUMENT(TSharedPtr<FWwiseTreeItem>, WaapiPickerItem)

		/** The parent widget */
		SLATE_ARGUMENT(TSharedPtr<SWidget>, ParentWidget)

		/** Callback to check if the widget is selected, should only be hooked up if parent widget is handling selection or focus. */
		SLATE_EVENT(FIsSelected, IsSelected)

		/** Text to highlight for this WwiseItem */
		SLATE_ATTRIBUTE(FText, HighlightText)

		SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);

		/** Trigger entry into edit mode */
		void EnterEditingMode();

	~SWaapiPickerRow();

private:

	/** Handles committing a name change */
	void HandleNameCommitted(const FText& NewText, ETextCommit::Type CommitInfo);

	/** Handles verifying a name change */
	bool HandleVerifyNameChanged(const FText& NewText, FText& OutErrorMessage);

	/** Checks whether the selected collection is not allowed to be renamed */
	bool IsWiseItemNameReadOnly() const;

	/** Returns the text of the WwiseItem name */
	FText GetNameText() const;

	/** Returns the text to use for the Wwise item tooltip */
	FText GetToolTipText() const;

private:
	/** Handler for when a name was given to a new item */
	bool OnVerifyItemNameChanged(const TSharedPtr< FWwiseTreeItem >& WwiseItem, const FString& InNewItemName, FText& OutErrorMessage);

	/** Handler for when a name was given to an item */
	bool OnItemRenameCommitted(const TSharedPtr< FWwiseTreeItem >& WwiseItem, const FString& InNewItemName, FText& OutWarningMessage);

public:

	struct KeyValueArgs
	{
		const FString keyArg;
		const FString valueArg;
	};

	/**
	* Call WAAPI to change the object name form the path or the id of the object (inFromIdOrPath).
	*
	* @param inUri		The Unique Resource Identifier used to indicate a specific action to WAAPI; i.e. ak::wwise::core::object::setName
	* @param values		An array that contains the pair of field and field value; e.i. when asking WAAPI to rename an item, the arguments are like this : {{object,id},{value,newname}}
	* @return			A boolean to ensure that the call was successfully done.
	*/
	static bool CallWaapiExecuteUri(const char* inUri, const TArray<KeyValueArgs>& values, TSharedPtr<FJsonObject>& outJsonResult);

private:
	/** A shared pointer to the parent widget. */
	TSharedPtr<SWidget> ParentWidget;

	/** The data for this item */
	TWeakPtr<FWwiseTreeItem> WaapiPickerItem;

	/** Widget to display the name of the item and allows for renaming */
	TSharedPtr< SInlineEditableTextBlock > InlineRenameWidget;

	/** Handle to the registered EnterEditingMode delegate. */
	FDelegateHandle EnterEditingModeDelegateHandle;

	/** Broadcasts whenever renaming a tree item is requested */
	DECLARE_MULTICAST_DELEGATE(FRenamedRequestEvent)

	/** Broadcasts whenever a rename is requested */
	FRenamedRequestEvent OnRenamedRequestEvent;
};
