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
AkWaapiUri.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
SAkWaapiUri
------------------------------------------------------------------------------------*/

#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STreeView.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Widgets/Input/SSearchBox.h"
#include "Misc/TextFilter.h"
#include "AkWaapiUri.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkUri, Log, All);

/**
* Structure for Uri
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWaapiUri
{
	GENERATED_USTRUCT_BODY()
		
	/**
	* The Uri
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = Uri, meta = (DisplayName = "Uri"))
	FString Uri;
};

/*------------------------------------------------------------------------------------
UAkWaapiUriConv
------------------------------------------------------------------------------------*/
UCLASS()
class AKAUDIO_API UAkWaapiUriConv : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/** Converts an AkWaapiUri value to a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (FAkWaapiUri)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_FAkWaapiUriToString(const FAkWaapiUri& INAkWaapiUri);

	/** Converts an AkWaapiUri value to a localizable text */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToText (FAkWaapiUri)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|Text")
	static FText Conv_FAkWaapiUriToText(const FAkWaapiUri& INAkWaapiUri);
};

typedef TTextFilter< const FString& > StringFilter;

/*------------------------------------------------------------------------------------
SAkWaapiUri
------------------------------------------------------------------------------------*/
class AKAUDIO_API SAkWaapiUri : public SCompoundWidget
{
public:
	typedef TSlateDelegates< TSharedPtr< FString > >::FOnSelectionChanged FOnSelectionChanged;

public:
	SLATE_BEGIN_ARGS(SAkWaapiUri)
		: _FocusSearchBoxWhenOpened(true)
		, _SelectionMode(ESelectionMode::Multi)
	{}

	/** Content displayed to the left of the search bar */
	SLATE_NAMED_SLOT(FArguments, SearchContent)

		/** If true, the search box will be focus the frame after construction */
		SLATE_ARGUMENT(bool, FocusSearchBoxWhenOpened)

		/** The selection mode for the list view */
		SLATE_ARGUMENT(ESelectionMode::Type, SelectionMode)

		/** Handles the drag and drop operations */
		SLATE_EVENT(FOnDragDetected, OnDragDetected)

		/** Handles the selection operation */
		SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged)

		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);
	SAkWaapiUri(void);
	~SAkWaapiUri();

	/** Returns all the Uris currently selected in the Waapi Picker view */
	const TArray<TSharedPtr<FString>> GetSelectedUri() const;

private:
	/** The tree view widget */
	TSharedPtr< SListView< TSharedPtr<FString>> > ListViewPtr;

	/** The Uri list search box */
	TSharedPtr< SSearchBox > SearchBoxPtr;

	/** Filter for the search box */
	TSharedPtr<StringFilter> SearchBoxFilter;

	/** Uri list */
	TArray< TSharedPtr<FString> > UriList;

	/** Delegate to invoke when drag drop detected. */
	FOnDragDetected OnDragDetected;

	/** Delegate to invoke when a Uri is selected. */
	FOnSelectionChanged OnSelectionChanged;

private:
	/** One-off active timer to focus the widget post-construct */
	EActiveTimerReturnType SetFocusPostConstruct(double InCurrentTime, float InDeltaTime);

	/** Generate a row in the tree view */
	TSharedRef<ITableRow> GenerateRow(TSharedPtr<FString> in_Uri, const TSharedRef<STableViewBase>& OwnerTable);

	/** Used by the search filter */
	void PopulateSearchStrings(const FString& in_Uri, OUT TArray< FString >& OutSearchStrings) const;
	void FilterUpdated();

	/** Handler for list view selection changes */
	void ListSelectionChanged(TSharedPtr< FString > in_Uri, ESelectInfo::Type SelectInfo);
};