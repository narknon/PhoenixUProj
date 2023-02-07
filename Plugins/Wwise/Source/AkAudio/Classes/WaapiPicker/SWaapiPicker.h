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
	SWaapiPicker.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
	SWaapiPicker
------------------------------------------------------------------------------------*/
#include "WwiseTreeItem.h"
#include "Misc/TextFilter.h"
#include "Widgets/Views/STableRow.h"
#include "AkWaapiClient.h"
#include "Dom/JsonObject.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Views/STreeView.h"
#include "Framework/Commands/UICommandList.h"
DECLARE_LOG_CATEGORY_EXTERN(LogAkAudioPicker, Log, All);

typedef TTextFilter< const FString& > StringFilter;

struct TransformStringField
{
	const FString keyArg;
	const TArray<FString> valueStringArgs;
	const TArray<int32> valueNumberArgs;
};

class AKAUDIO_API SWaapiPicker : public SCompoundWidget
{
public:
	typedef TSlateDelegates< TSharedPtr< FWwiseTreeItem > >::FOnSelectionChanged FOnSelectionChanged;

	DECLARE_DELEGATE(FOnGenerateSoundBankClicked);

public:
	SLATE_BEGIN_ARGS( SWaapiPicker )
		: _FocusSearchBoxWhenOpened(false)
		, _ShowTreeTitle(true)
		, _ShowSearchBar(true)
		, _ShowSeparator(true)
		, _AllowContextMenu(true)
		, _RestrictContextMenu(false)
		, _ShowGenerateSoundBanksButton(false)
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

		/** If true, editor options (like explore section) will be restricted from the context menu */
		SLATE_ARGUMENT(bool, RestrictContextMenu)

		/** If true, it will show the Generate SoundBanks button */
		SLATE_ARGUMENT(bool, ShowGenerateSoundBanksButton)

		/** The selection mode for the tree view */
		SLATE_ARGUMENT( ESelectionMode::Type, SelectionMode )
		
		/** Handles the drag and drop operations */
		SLATE_EVENT(FOnDragDetected, OnDragDetected)

		/** Handles the selection operation */
		SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged)

		/** Handles the Generate SoundBanks click operation */
		SLATE_EVENT(FOnGenerateSoundBankClicked, OnGenerateSoundBanksClicked)

	SLATE_END_ARGS( )

	void Construct(const FArguments& InArgs);
	SWaapiPicker(void);
	~SWaapiPicker();

	static const FName WaapiPickerTabName;
	static const FText ModalWarning;
    
    virtual void Tick( const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime ) override;

	/**
	* Call WAAPI to get information about an object form the path or the id of the object (inFrom).
	*
	* @param inFromField	 The path or the id from which the data will be get.
	* @param outJsonResult   A JSON object that contains useful informations about the call process, gets the object infos or gets an error infos in case the call failed.
	* @return			     A boolean to ensure that the call was successfully done.
	*/
	static bool CallWaapiGetInfoFrom(const FString& inFromField, const FString& inFromString, TSharedPtr<FJsonObject>& outJsonResult, const TArray<TransformStringField>& TransformFields);

	/**
	* Check if an item exists in the ItemTree, using the item path.
	*
	* @param RootItem		   The root of the item we are looking for.
	* @param CurrentItemPath   The path of the item we are looking for.
	* @return			       The item that we are looking for if it exists, otherwise an invalid one.
	*/
	TSharedPtr<FWwiseTreeItem> FindItemFromPath(const TSharedPtr<FWwiseTreeItem>& RootItem, const FString& CurrentItemPath);

	/**
	* Construct the tree items within the CurrentItem path.
	*
	* @param CurrentItem the current item already created and need to create his parents from his path.
	*/
	void FindAndCreateItems(TSharedPtr<FWwiseTreeItem> CurrentItem);

	/**
	* Allows to get the root of an item from the path specified.
	*
	* @param InFullPath		A path used to search for the right root item from the root list.
	* @return				The root item correspondent to the full path.
	*/
	inline TSharedPtr<FWwiseTreeItem> GetRootItem(const FString& InFullPath);

	/**
	* Allows to get information from a FJsonValue object and use it to create an FWwiseTreeItem.
	*
	* @param inJsonItem		An FJsonValue from which we get utile data to construct the  FWwiseTreeItem object.
	* @return				An FWwiseTreeItem that will be added to the root items.
	*/
	TSharedPtr<FWwiseTreeItem> ConstructWwiseTreeItem(const TSharedPtr<FJsonValue>& InJsonItem);
	TSharedPtr<FWwiseTreeItem> ConstructWwiseTreeItem(const TSharedPtr<FJsonObject>& ItemInfoObj);

	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyboardEvent) override;

	/** Returns all the items currently selected in the Waapi Picker view */
	const TArray<TSharedPtr<FWwiseTreeItem>> GetSelectedItems() const;

	const FString GetSearchText() const;
	const void SetSearchText(const FString& newText);

private:
	/** The tree view widget */
	TSharedPtr< STreeView< TSharedPtr<FWwiseTreeItem>> > TreeViewPtr;

	/** The asset tree search box */
	TSharedPtr< SSearchBox > SearchBoxPtr;

	/** Filter for the search box */
	TSharedPtr<StringFilter> SearchBoxFilter;

	/** Root items (only events for now). */
	FCriticalSection RootItemsLock;
	TArray< TSharedPtr<FWwiseTreeItem> > RootItems;

	FGraphEventRef ConstructTreeTask;

	/** Bool to prevent the selection changed callback from running */
	bool AllowTreeViewDelegates;

	/** Remember the selected items. Useful when filtering to preserve selection status. */
	TSet< FGuid > LastSelectedItems;

	/** Remember the expanded items. Useful when filtering to preserve expansion status. */
	TSet< FGuid > LastExpandedItems;
	
	struct TransportInfo
	{
		int32 TransportID;
		uint64 SubscriptionID;

		TransportInfo(int32 transID, uint64 subsID) : TransportID(transID), SubscriptionID(subsID) {}
	};

	/** Remember the played items. Useful to play/stop and event. */
	TMap<FGuid, TransportInfo> ItemToTransport;

	/** Commands handled by this widget */
	TSharedRef<FUICommandList> CommandList;

	/** Delegate to invoke when drag drop detected. */
	FOnDragDetected OnDragDetected;
	
	/** Delegate to invoke when an item is selected. */
	FOnSelectionChanged OnSelectionChanged;

	FOnGenerateSoundBankClicked OnGenerateSoundBanksClicked;

	/** Whether to disable the context menu and keyboard controls of the explore section*/
	bool bRestrictContextMenu;

	/* Callback handles. */
	FDelegateHandle ProjectLoadedHandle;
	FDelegateHandle ConnectionLostHandle;
	FDelegateHandle ClientBeginDestroyHandle;

	//Waapi Client callbacks
	void RemoveClientCallbacks();
	void OnProjectLoadedCallback();
	void OnConnectionLostCallback();

	/* Used to show/hide the Picker/Warning */
	EVisibility isPickerAllowed() const;
	EVisibility isWarningVisible() const;
	FText GetWarningText() const;
	bool isPickerVisible;
	bool isModalActiveInWwise = false;

	/** One-off active timer to focus the widget post-construct */
	EActiveTimerReturnType SetFocusPostConstruct(double InCurrentTime, float InDeltaTime);

	/** Ran when the Populate button is clicked. Populates the window. */
	FReply OnPopulateClicked();

	FReply OnGenerateSoundBanksButtonClicked();

	/** Populates the picker window only (does not parse the Wwise project) */
	void ConstructTree();

	/** Generate a row in the tree view */
	TSharedRef<ITableRow> GenerateRow( TSharedPtr<FWwiseTreeItem> TreeItem, const TSharedRef<STableViewBase>& OwnerTable );

	/** Get the children of a specific tree element */
	void GetChildrenForTree( TSharedPtr< FWwiseTreeItem > TreeItem, TArray< TSharedPtr<FWwiseTreeItem> >& OutChildren );

	/** Handle Drag & Drop */
	FReply HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent);

	void ExpandFirstLevel();
	void ExpandParents(TSharedPtr<FWwiseTreeItem> Item);

	FText GetProjectName() const;

	/** Used by the search filter */
	void PopulateSearchStrings( const FString& FolderName, OUT TArray< FString >& OutSearchStrings ) const;
	void OnSearchBoxChanged( const FText& InSearchText );
	FText GetHighlightText() const;
	void FilterUpdated();
	void SetItemVisibility(TSharedPtr<FWwiseTreeItem> Item, bool IsVisible);
	void ApplyFilter();
	void RestoreTreeExpansion(const TArray< TSharedPtr<FWwiseTreeItem> >& Items);

	/** Handler for tree view selection changes */
	void TreeSelectionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type SelectInfo );

	/** Handler for tree view expansion changes */
	void TreeExpansionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, bool bIsExpanded );

	FString ProjectFolder;
	FString ProjectName;

	/** True if the specified item is selected in the asset tree */
	bool IsTreeItemSelected(TSharedPtr<FWwiseTreeItem> TreeItem) const;
	
	/** Builds the command list for the context menu on Waapi Picker items. */
	void CreateWaapiPickerCommands();

	/** Callback for creating a context menu for the Wwise items list. */
	TSharedPtr<SWidget> MakeWaapiPickerContextMenu();

	/** Helper functions for playback */
	int32 CreateTransport(const FGuid& ItemID);
	void DestroyTransport(const FGuid& ItemID);
	void TogglePlayStop(int32 TransportID);
	void StopTransport(int32 TransportID);
	uint64 SubscribeToTransportStateChanged(int32 TransportID);
	void HandleStateChanged(TSharedPtr<FJsonObject> UEJsonObject);
	
	/** Callback returns true if the rename command can be executed. */
	bool HandleRenameWwiseItemCommandCanExecute() const;
	
	/** Callback to execute the rename command from the context menu. */
	void HandleRenameWwiseItemCommandExecute() const;
	
	/** Callback returns true if the play command can be executed. */
	bool HandlePlayWwiseItemCommandCanExecute() const;

	/** Callback to execute the play command from the context menu. */
	void HandlePlayWwiseItemCommandExecute();
	
	/** Callback to execute the stop all command from the context menu. */
	void StopAndDestroyAllTransports();

	/** Callback returns true if the delete command can be executed. */
	bool HandleDeleteWwiseItemCommandCanExecute() const;

	/** Callback to execute the delete command from the context menu. */
	void HandleDeleteWwiseItemCommandExecute();	
	
	/** Callback to execute the explore item command from the context menu. */
	void HandleExploreWwiseItemCommandExecute() const;

	/** Callback returns true if the command can be executed. */
	bool HandleWwiseCommandCanExecute() const;

	/** Callback to execute the find item in project explorer command from the context menu. */
	void HandleFindWwiseItemInProjectExplorerCommandExecute() const;

	/** Callback to execute the refresh command from the context menu. */
	void HandleRefreshWaapiPickerCommandExecute();

	/** Callback to execute the undo command */
	void HandleUndoWaapiPickerCommandExecute() const;

	/** Callback to execute the redo command */
	void HandleRedoWaapiPickerCommandExecute() const;

	void SubscribeWaapiCallbacks();
	void UnsubscribeWaapiCallbacks();

	void OnWaapiRenamed(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void OnWaapiChildAdded(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void OnWaapiChildRemoved(uint64_t Id, TSharedPtr<FJsonObject> Response);
	void OnWwiseSelectionChanged(uint64_t Id, TSharedPtr<FJsonObject> Response);

	void CreateTreeItemWaapi(const TSharedPtr<FWwiseTreeItem>& parentTreeItem, const TSharedPtr<FJsonObject>& childJson);

	template<typename ActionFunctor>
	void HandleOnWaapiChildResponse(TSharedPtr<FJsonObject> Response, const ActionFunctor& Action);

	TSharedPtr<FWwiseTreeItem> FindTreeItemFromJsonObject(const TSharedPtr<FJsonObject>& Object, const FString& OverrideLastPart = FString());
	TSharedPtr<FWwiseTreeItem> FindOrConstructTreeItemFromJsonObject(const TSharedPtr<FJsonObject>& Object);

private:
	struct FWaapiSubscriptionIds
	{
		uint64 Renamed = 0;
		uint64 ChildAdded = 0;
		uint64 ChildRemoved = 0;
		uint64 SelectionChanged = 0;
	} WaapiSubscriptionIds;

	TMap<FGuid, TSharedPtr<FWwiseTreeItem>> pendingTreeItems;
};