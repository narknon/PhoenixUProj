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
AkWaapiFieldNames.cpp
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
includes.
------------------------------------------------------------------------------------*/
#include "AkWaapiBlueprints/AkWaapiFieldNames.h"
#include "AkAudioDevice.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Input/SButton.h"
#include "Misc/ScopedSlowTask.h"
#include "Framework/Application/SlateApplication.h"
#include "AkAudioStyle.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY(LogAkFieldNames);

/*------------------------------------------------------------------------------------
Statics and Globals
------------------------------------------------------------------------------------*/
namespace SAkWaapiFieldNames_Helpers
{
	static const FString FullFieldNamesList[] =
	{
		TEXT("id"),
		TEXT("return"),
		TEXT("path"),
		TEXT("filePath"),
		TEXT("from"),
		TEXT("name"),
		TEXT("type"),
		TEXT("children"),
		TEXT("childrenCount"),
		TEXT("ancestors"),
		TEXT("descendants"),
		TEXT("workunit:type"),
		TEXT("Folder"),
		TEXT("PhysicalFolder"),
		TEXT("search"),
		TEXT("parent"),
		TEXT("select"),
		TEXT("transform"),
		TEXT("object"),
		TEXT("objects"),
		TEXT("value"),
		TEXT("command"),
		TEXT("transport"),
		TEXT("action"),
		TEXT("play"),
		TEXT("stop"),
		TEXT("stopped"),
		TEXT("displayName"),
		TEXT("Delete Items"),
		TEXT("Drag Drop Items"),
		TEXT("Undo"),
		TEXT("Redo"),
		TEXT("state"),
		TEXT("ofType"),
		TEXT("Project"),
		TEXT("property"),
		TEXT("Volume"),
		TEXT("newName"),
		TEXT("oldName"),
		TEXT("new"),
		TEXT("classId"),
		TEXT("FindInProjectExplorerSyncGroup1")
	};

	enum { FullFieldNamesListSize = sizeof(FullFieldNamesList) / sizeof(*FullFieldNamesList) };
}
/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
USAkWaapiFieldNamesConv
------------------------------------------------------------------------------------*/
USAkWaapiFieldNamesConv::USAkWaapiFieldNamesConv(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Property initialization
}

FString USAkWaapiFieldNamesConv::Conv_FAkWaapiFieldNamesToString(const FAkWaapiFieldNames& INAkWaapiFieldNames)
{
	return INAkWaapiFieldNames.FieldName;
}

FText USAkWaapiFieldNamesConv::Conv_FAkWaapiFieldNamesToText(const FAkWaapiFieldNames& INAkWaapiFieldNames)
{
	return FText::FromString(*INAkWaapiFieldNames.FieldName);
}

/*------------------------------------------------------------------------------------
SAkWaapiFieldNames
------------------------------------------------------------------------------------*/
SAkWaapiFieldNames::SAkWaapiFieldNames()
{}

SAkWaapiFieldNames::~SAkWaapiFieldNames()
{}

void SAkWaapiFieldNames::Construct(const FArguments& InArgs)
{
	OnDragDetected = InArgs._OnDragDetected;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	if (InArgs._FocusSearchBoxWhenOpened)
	{
		RegisterActiveTimer(0.f, FWidgetActiveTimerDelegate::CreateSP(this, &SAkWaapiFieldNames::SetFocusPostConstruct));
	}

	SearchBoxFilter = MakeShareable(new StringFilter(StringFilter::FItemToStringArray::CreateSP(this, &SAkWaapiFieldNames::PopulateSearchStrings)));
	SearchBoxFilter->OnChanged().AddSP(this, &SAkWaapiFieldNames::FilterUpdated);

	ChildSlot
		[
			SNew(SBorder)
			.Padding(4)
			.BorderImage(FAkAudioStyle::GetBrush("AudiokineticTools.GroupBorder"))
			[
				SNew(SVerticalBox)
				// Search
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0, 1, 0, 3)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						InArgs._SearchContent.Widget
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SAssignNew(SearchBoxPtr, SSearchBox)
						.HintText(LOCTEXT("FieldNameSearchHint", "Search a Field Name"))
						.ToolTipText(LOCTEXT("FieldNameSearchTooltip", "Type here to search for a Field Name"))
						.OnTextChanged(SearchBoxFilter.Get(), &StringFilter::SetRawFilterText)
						.SelectAllTextWhenFocused(false)
						.DelayChangeNotificationsWhileTyping(true)
					]
				]
				// Tree
				+ SVerticalBox::Slot()
				.FillHeight(1.f)
				[
					SAssignNew(ListViewPtr, SListView< TSharedPtr<FString> >)
					.ListItemsSource(&FieldNamesList)
					.OnGenerateRow(this, &SAkWaapiFieldNames::GenerateRow)
					.ItemHeight(18)
					.SelectionMode(InArgs._SelectionMode)
					.OnSelectionChanged(this, &SAkWaapiFieldNames::ListSelectionChanged)
					.ClearSelectionOnClick(false)
				]
			]
		];
	
	for (const auto& FieldName : SAkWaapiFieldNames_Helpers::FullFieldNamesList)
	{
		FieldNamesList.Add(MakeShareable(new FString(FieldName)));
	}
	FieldNamesList.Sort([](TSharedPtr< FString > Firststr, TSharedPtr< FString > Secondstr) { return *Firststr.Get() < *Secondstr.Get(); });
	ListViewPtr->RequestListRefresh();
}

TSharedRef<ITableRow> SAkWaapiFieldNames::GenerateRow(TSharedPtr<FString> in_FieldName, const TSharedRef<STableViewBase>& OwnerTable)
{
	check(in_FieldName.IsValid());

	TSharedPtr<ITableRow> NewRow = SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		[
			SNew(STextBlock)
			.Text(FText::FromString(*in_FieldName.Get()))
		.HighlightText(SearchBoxFilter.Get(), &StringFilter::GetRawFilterText)
		];
	return NewRow.ToSharedRef();
}

void SAkWaapiFieldNames::PopulateSearchStrings(const FString& in_FieldName, OUT TArray< FString >& OutSearchStrings) const
{
	OutSearchStrings.Add(in_FieldName);
}

void SAkWaapiFieldNames::FilterUpdated()
{
	FScopedSlowTask SlowTask(2.f, LOCTEXT("AK_PopulatingPicker", "Populating FieldName Picker..."));
	SlowTask.MakeDialog();

	FieldNamesList.Empty(SAkWaapiFieldNames_Helpers::FullFieldNamesListSize);

	FString FilterString = SearchBoxFilter->GetRawFilterText().ToString();
	if (FilterString.IsEmpty())
	{
		for (const auto& FieldName : SAkWaapiFieldNames_Helpers::FullFieldNamesList)
		{
			FieldNamesList.Add(MakeShareable(new FString(FieldName)));
		}
	}
	else
	{
		for (const auto& FieldName : SAkWaapiFieldNames_Helpers::FullFieldNamesList)
		{
			if (FieldName.Contains(FilterString))
			{
				FieldNamesList.Add(MakeShareable(new FString(FieldName)));
			}
		}
	}
	FieldNamesList.Sort([](TSharedPtr< FString > Firststr, TSharedPtr< FString > Secondstr) { return *Firststr.Get() < *Secondstr.Get(); });
	ListViewPtr->RequestListRefresh();
}

void SAkWaapiFieldNames::ListSelectionChanged(TSharedPtr< FString > in_FieldName, ESelectInfo::Type /*SelectInfo*/)
{
	if (OnSelectionChanged.IsBound())
		OnSelectionChanged.Execute(in_FieldName, ESelectInfo::OnMouseClick);
}

const TArray<TSharedPtr<FString>> SAkWaapiFieldNames::GetSelectedFieldNames() const
{
	return ListViewPtr->GetSelectedItems();
}

EActiveTimerReturnType SAkWaapiFieldNames::SetFocusPostConstruct(double InCurrentTime, float InDeltaTime)
{
	FWidgetPath WidgetToFocusPath;
	FSlateApplication::Get().GeneratePathToWidgetUnchecked(SearchBoxPtr.ToSharedRef(), WidgetToFocusPath);
	FSlateApplication::Get().SetKeyboardFocus(WidgetToFocusPath, EFocusCause::SetDirectly);

	return EActiveTimerReturnType::Stop;
}
#undef LOCTEXT_NAMESPACE