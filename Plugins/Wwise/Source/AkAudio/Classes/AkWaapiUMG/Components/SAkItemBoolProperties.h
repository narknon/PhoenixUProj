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
	AkItemProperties.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
	SAkItemBoolProperties
------------------------------------------------------------------------------------*/

#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STreeView.h"
#include "Widgets/Input/SSearchBox.h"
#include "Misc/TextFilter.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkItemBoolProperties, Log, All);

typedef TTextFilter< const FString& > StringFilter;

class AKAUDIO_API SAkItemBoolProperties : public SCompoundWidget
{
public:
	typedef TSlateDelegates< TSharedPtr< FString > >::FOnSelectionChanged FOnSelectionChanged;

public:
	SLATE_BEGIN_ARGS(SAkItemBoolProperties)
		: _FocusSearchBoxWhenOpened(false)
		, _SelectionMode( ESelectionMode::Multi )
		{}

		/** Content displayed to the left of the search bar */
		SLATE_NAMED_SLOT( FArguments, SearchContent )

		/** If true, the search box will be focus the frame after construction */
		SLATE_ARGUMENT( bool, FocusSearchBoxWhenOpened )

		/** The selection mode for the list view */
		SLATE_ARGUMENT( ESelectionMode::Type, SelectionMode )
		
		/** Handles the drag and drop operations */
		SLATE_EVENT(FOnDragDetected, OnDragDetected)

		/** Handles the selection operation */
		SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged)

	SLATE_END_ARGS( )

	void Construct(const FArguments& InArgs);
	SAkItemBoolProperties(void);
	~SAkItemBoolProperties();

	/** Returns all properties currently selected in the Wwise properties list */
	const TArray<TSharedPtr<FString>> GetSelectedProperties() const;

	const FString GetSearchText() const;
	const void SetSearchText(const FString& newText);

private:
	/** The tree view widget */
	TSharedPtr< SListView< TSharedPtr<FString>> > ListViewPtr;

	/** The property list search box */
	TSharedPtr< SSearchBox > SearchBoxPtr;

	/** Filter for the search box */
	TSharedPtr<StringFilter> SearchBoxFilter;

	/** Property list */
	TArray< TSharedPtr<FString> > PropertiesList;

	/** Delegate to invoke when drag drop detected. */
	FOnDragDetected OnDragDetected;
	
	/** Delegate to invoke when a property is selected. */
	FOnSelectionChanged OnSelectionChanged;

private:
	/** One-off active timer to focus the widget post-construct */
	EActiveTimerReturnType SetFocusPostConstruct(double InCurrentTime, float InDeltaTime);

	/** Generate a row in the tree view */
	TSharedRef<ITableRow> GenerateRow( TSharedPtr<FString> ItemProperty, const TSharedRef<STableViewBase>& OwnerTable );

	/** Handle Drag & Drop */
	FReply HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent);

	/** Used by the search filter */
	void PopulateSearchStrings( const FString& PropertyName, OUT TArray< FString >& OutSearchStrings ) const;
	void FilterUpdated();

	/** Handler for list view selection changes */
	void ListSelectionChanged( TSharedPtr< FString > ItemProperty, ESelectInfo::Type SelectInfo );
};