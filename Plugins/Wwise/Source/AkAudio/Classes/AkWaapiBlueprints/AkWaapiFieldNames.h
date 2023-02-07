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
AkWaapiFieldNames.h
------------------------------------------------------------------------------------*/
#pragma once

/*------------------------------------------------------------------------------------
SAkWaapiFieldNames
------------------------------------------------------------------------------------*/

#include "Misc/TextFilter.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STreeView.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Widgets/Input/SSearchBox.h"
#include "AkWaapiFieldNames.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkFieldNames, Log, All);

/**
* Structure for Field Names
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWaapiFieldNames
{
	GENERATED_USTRUCT_BODY()
		
	/**
	* The Field Name
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FieldName, meta = (DisplayName = "Field Name"))
	FString FieldName;
};

/*------------------------------------------------------------------------------------
USAkWaapiFieldNamesConv
------------------------------------------------------------------------------------*/
UCLASS()
class AKAUDIO_API USAkWaapiFieldNamesConv : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/** Converts an AkWaapiFieldName value to a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (FAkWaapiFieldNames)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_FAkWaapiFieldNamesToString(const FAkWaapiFieldNames& INAkWaapiFieldNames);

	/** Converts an AkWaapiFieldName value to a localizable text */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToText (FAkWaapiFieldNames)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|Text")
	static FText Conv_FAkWaapiFieldNamesToText(const FAkWaapiFieldNames& INAkWaapiFieldNames);
};

typedef TTextFilter< const FString& > StringFilter;

/*------------------------------------------------------------------------------------
SAkWaapiFieldNames
------------------------------------------------------------------------------------*/
class AKAUDIO_API SAkWaapiFieldNames : public SCompoundWidget
{
public:
	typedef TSlateDelegates< TSharedPtr< FString > >::FOnSelectionChanged FOnSelectionChanged;

public:
	SLATE_BEGIN_ARGS(SAkWaapiFieldNames)
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
	SAkWaapiFieldNames(void);
	~SAkWaapiFieldNames();

	/** Returns all the FieldNames currently selected in the Waapi Picker view */
	const TArray<TSharedPtr<FString>> GetSelectedFieldNames() const;

private:
	/** The tree view widget */
	TSharedPtr< SListView< TSharedPtr<FString>> > ListViewPtr;

	/** The FieldNames list search box */
	TSharedPtr< SSearchBox > SearchBoxPtr;

	/** Filter for the search box */
	TSharedPtr<StringFilter> SearchBoxFilter;

	/** Field Names list */
	TArray< TSharedPtr<FString> > FieldNamesList;

	/** Delegate to invoke when drag drop detected. */
	FOnDragDetected OnDragDetected;

	/** Delegate to invoke when a Field Name is selected. */
	FOnSelectionChanged OnSelectionChanged;

private:
	/** One-off active timer to focus the widget post-construct */
	EActiveTimerReturnType SetFocusPostConstruct(double InCurrentTime, float InDeltaTime);

	/** Generate a row in the tree view */
	TSharedRef<ITableRow> GenerateRow(TSharedPtr<FString> in_FieldName, const TSharedRef<STableViewBase>& OwnerTable);

	/** Used by the search filter */
	void PopulateSearchStrings(const FString& in_FieldName, OUT TArray< FString >& OutSearchStrings) const;
	void FilterUpdated();

	/** Handler for list view selection changes */
	void ListSelectionChanged(TSharedPtr< FString > in_FieldName, ESelectInfo::Type SelectInfo);
};