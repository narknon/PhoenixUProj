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
	SWwisePicker.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
	SWwisePicker
------------------------------------------------------------------------------------*/
#include "Misc/TextFilter.h"
#include "WaapiPicker/WwiseTreeItem.h"
#include "Widgets/Views/STreeView.h"
#include "WwiseProject/WwiseWorkUnitParser.h"

using StringFilter = TTextFilter<const FString&>;

class WwisePickerBuilderVisitor;

class SWwisePicker : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS( SWwisePicker )
		: _FocusSearchBoxWhenOpened(false)
		, _ShowTreeTitle(true)
		, _ShowSearchBar(true)
		, _ShowSeparator(true)
		, _AllowContextMenu(true)
		, _SelectionMode( ESelectionMode::Multi )
		{}

		/** Content displayed to the left of the search bar */
		SLATE_NAMED_SLOT( FArguments, SearchContent )

		/** If true, the search box will be focus the frame after construction */
		SLATE_ARGUMENT( bool, FocusSearchBoxWhenOpened )

		/** If true, The tree title will be displayed */
		SLATE_ARGUMENT( bool, ShowTreeTitle )

		/** If true, The tree search bar will be displayed */
		SLATE_ARGUMENT( bool, ShowSearchBar )

		/** If true, The tree search bar separator be displayed */
		SLATE_ARGUMENT( bool, ShowSeparator )

		/** If false, the context menu will be suppressed */
		SLATE_ARGUMENT( bool, AllowContextMenu )

		/** The selection mode for the tree view */
		SLATE_ARGUMENT( ESelectionMode::Type, SelectionMode )
	SLATE_END_ARGS( )

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs);
	SWwisePicker(void);
	~SWwisePicker();

	AUDIOKINETICTOOLS_API static const FName WwisePickerTabName;

	AUDIOKINETICTOOLS_API void ForceRefresh();

	AUDIOKINETICTOOLS_API void InitialParse();
    
    virtual void Tick( const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime ) override;

	static FReply DoDragDetected(const FPointerEvent& MouseEvent, const TArray<TSharedPtr<FWwiseTreeItem>>& SelectedItems);

private:
	/** The tree view widget */
	TSharedPtr< STreeView< TSharedPtr<FWwiseTreeItem>> > TreeViewPtr;

	/** Filter for the search box */
	TSharedPtr<StringFilter> SearchBoxFilter;

	/** Root items (only events for now). */
	TArray< TSharedPtr<FWwiseTreeItem> > RootItems;

	/** Bool to prevent the selection changed callback from running */
	bool AllowTreeViewDelegates;

	/** Remember the selected items. Useful when filtering to preserve selection status. */
	TSet< FString > LastSelectedPaths;

	/** Remember the expanded items. Useful when filtering to preserve expansion status. */
	TSet< FString > LastExpandedPaths;

	/** Ran when the Populate button is clicked. Parses the Wwise project (using the WwiseWwuParser) and populates the window. */
	FReply OnPopulateClicked();

	FReply OnGenerateSoundBanksClicked();

	/** Populates the picker window only (does not parse the Wwise project) */
	void ConstructTree();

	/** Change the watched folder for the wwu parser */
	void UpdateDirectoryWatcher();

	/** Generate a row in the tree view */
	TSharedRef<ITableRow> GenerateRow( TSharedPtr<FWwiseTreeItem> TreeItem, const TSharedRef<STableViewBase>& OwnerTable );

	/** Get the children of a specific tree element */
	void GetChildrenForTree( TSharedPtr< FWwiseTreeItem > TreeItem, TArray< TSharedPtr<FWwiseTreeItem> >& OutChildren );

	/** Handle Drag & Drop */
	FReply OnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent);

	void ExpandFirstLevel();
	void ExpandParents(TSharedPtr<FWwiseTreeItem> Item);

	FText GetProjectName() const;

	/** Used by the search filter */
	void PopulateSearchStrings( const FString& FolderName, OUT TArray< FString >& OutSearchStrings ) const;
	void OnSearchBoxChanged( const FText& InSearchText );
	FText GetHighlightText() const;
	void FilterUpdated();
	void SetItemVisibility(TSharedPtr<FWwiseTreeItem> Item, bool IsVisible);
	void RestoreTreeExpansion(const TArray< TSharedPtr<FWwiseTreeItem> >& Items);

	/** Handler for tree view selection changes */
	void TreeSelectionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type SelectInfo );

	/** Handler for tree view expansion changes */
	void TreeExpansionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, bool bIsExpanded );

	void OnProjectDirectoryChanged(const TArray<struct FFileChangeData>& ChangedFiles);
	FDelegateHandle ProjectDirectoryModifiedDelegateHandle;
	FString ProjectFolder;
	FString ProjectName;


	/* Callback handles. */
	FDelegateHandle ProjectLoadedHandle;
	FDelegateHandle ConnectionLostHandle;
	FDelegateHandle ClientBeginDestroyHandle;
	void RemoveClientCallbacks();

	/* Used to show/hide the Picker/Warning */
	EVisibility isPickerAllowed() const;
	EVisibility isWarningVisible() const;
	bool isPickerVisible;

	WwiseWorkUnitParser workUnitParser;
	TUniquePtr<WwisePickerBuilderVisitor> builderVisitor;
};