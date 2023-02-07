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
	SAkItemBoolProperties.cpp
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
 includes.
------------------------------------------------------------------------------------*/
#include "AkWaapiUMG/Components/SAkItemBoolProperties.h"
#include "AkAudioDevice.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Input/SButton.h"
#include "Misc/ScopedSlowTask.h"
#include "AkAudioStyle.h"
#include "Framework/Application/SlateApplication.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY(LogAkItemBoolProperties);

/*------------------------------------------------------------------------------------
Statics and Globals
------------------------------------------------------------------------------------*/
namespace SAkItemBoolProperties_Helpers
{
	static const FString FullBoolPropertiesList[] =
	{
		TEXT("BypassEffect"),
		TEXT("BypassEffect0"),
		TEXT("BypassEffect1"),
		TEXT("BypassEffect2"),
		TEXT("BypassEffect3"),
#if AK_WWISESDK_VERSION_MAJOR <= 2017
		TEXT("DynamicPositioning"),
#endif
#if AK_WWISESDK_VERSION_MAJOR >= 2019
		TEXT("EnableAttenuation"),
#endif
		TEXT("EnableLoudnessNormalization"),
		TEXT("EnableMidiNoteTracking"),
#if AK_WWISESDK_VERSION_MAJOR <= 2017
		TEXT("EnablePanner"),
		TEXT("EnablePositioning"),
		TEXT("FollowListenerOrientation"),
#endif
		TEXT("HdrEnableEnvelope"),
#if AK_WWISESDK_VERSION_MAJOR >= 2018
		TEXT("HoldEmitterPositionOrientation"),
		TEXT("HoldListenerOrientation"),
#endif
		TEXT("IgnoreParentMaxSoundInstance"),
		TEXT("Inclusion"),
		TEXT("IsLoopingEnabled"),
		TEXT("IsLoopingInfinite"),
		TEXT("IsNonCachable"),
		TEXT("IsStreamingEnabled"),
		TEXT("IsZeroLantency"),
#if AK_WWISESDK_VERSION_MAJOR >= 2018
		TEXT("ListenerRelativeRouting"),
#endif
		TEXT("MidiBreakOnNoteOff"),
		TEXT("OverrideAnalysis"),
		TEXT("OverrideConversion"),
		TEXT("OverrideEffect"),
		TEXT("OverrideGameAuxSends"),
		TEXT("OverrideHdrEnvelope"),
		TEXT("OverrideMidiEventsBehavior"),
		TEXT("OverrideMidiNoteTracking"),
		TEXT("OverrideOutput"),
		TEXT("OverridePositioning"),
		TEXT("OverridePriority"),
		TEXT("OverrideUserAuxSends"),
		TEXT("OverrideVirtualVoice"),
		TEXT("PriorityDistanceFactor"),
		TEXT("RenderEffect0"),
		TEXT("RenderEffect1"),
		TEXT("RenderEffect2"),
		TEXT("RenderEffect3"),
#if AK_WWISESDK_VERSION_MAJOR <= 2017
		TEXT("Spatialization"),
#endif
		TEXT("UseGameAuxSends"),
		TEXT("UseMaxSoundPerInstance")
	};

	enum { FullBoolPropertiesListSize = sizeof(FullBoolPropertiesList) / sizeof(*FullBoolPropertiesList) };
}
/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
SAkItemBoolProperties
------------------------------------------------------------------------------------*/
SAkItemBoolProperties::SAkItemBoolProperties()
{}

SAkItemBoolProperties::~SAkItemBoolProperties()
{}

void SAkItemBoolProperties::Construct(const FArguments& InArgs)
{
	OnDragDetected = InArgs._OnDragDetected;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	if (InArgs._FocusSearchBoxWhenOpened)
	{
		RegisterActiveTimer(0.f, FWidgetActiveTimerDelegate::CreateSP(this, &SAkItemBoolProperties::SetFocusPostConstruct));
	}

	SearchBoxFilter = MakeShareable( new StringFilter( StringFilter::FItemToStringArray::CreateSP( this, &SAkItemBoolProperties::PopulateSearchStrings ) ) );
	SearchBoxFilter->OnChanged().AddSP( this, &SAkItemBoolProperties::FilterUpdated );
  
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
					SAssignNew(SearchBoxPtr,SSearchBox)
					.HintText( LOCTEXT( "PropertiesSearchHint", "Search an item property" ) )
					.ToolTipText(LOCTEXT("PropertiesSearchTooltip", "Type here to search for a property"))
					.OnTextChanged(SearchBoxFilter.Get(), &StringFilter::SetRawFilterText)
					.SelectAllTextWhenFocused(false)
					.DelayChangeNotificationsWhileTyping(true)
				]
			]		
			// Tree
			+SVerticalBox::Slot()
			.FillHeight(1.f)
			[
				SAssignNew(ListViewPtr, SListView< TSharedPtr<FString> >)
				.ListItemsSource(&PropertiesList)
				.OnGenerateRow( this, &SAkItemBoolProperties::GenerateRow )
				.ItemHeight(18)
				.SelectionMode(InArgs._SelectionMode)
				.OnSelectionChanged(this, &SAkItemBoolProperties::ListSelectionChanged)
				.ClearSelectionOnClick(false)
			]
		]
	];
	
	for (const auto& Property : SAkItemBoolProperties_Helpers::FullBoolPropertiesList)
	{
		PropertiesList.Add(MakeShareable(new FString(Property)));
	}
	ListViewPtr->RequestListRefresh();
}

TSharedRef<ITableRow> SAkItemBoolProperties::GenerateRow( TSharedPtr<FString> ItemProperty, const TSharedRef<STableViewBase>& OwnerTable )
{
	check(ItemProperty.IsValid());
	
	TSharedPtr<ITableRow> NewRow = SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		.OnDragDetected(this, &SAkItemBoolProperties::HandleOnDragDetected)
		[
			SNew(STextBlock)
			.Text(FText::FromString(*ItemProperty.Get()))
			.HighlightText(SearchBoxFilter.Get(), &StringFilter::GetRawFilterText)
		];
	return NewRow.ToSharedRef();
}

FReply SAkItemBoolProperties::HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{		
	// Refresh the contents
	if(OnDragDetected.IsBound())
		return OnDragDetected.Execute(Geometry,MouseEvent);
	return FReply::Unhandled();
}

void SAkItemBoolProperties::PopulateSearchStrings( const FString& PropertyName, OUT TArray< FString >& OutSearchStrings ) const
{
	OutSearchStrings.Add( PropertyName );
}

void SAkItemBoolProperties::FilterUpdated()
{
	FScopedSlowTask SlowTask(2.f, LOCTEXT("AK_PopulatingPicker", "Populating Properties Picker..."));
	SlowTask.MakeDialog();

	PropertiesList.Empty(SAkItemBoolProperties_Helpers::FullBoolPropertiesListSize);

	FString FilterString = SearchBoxFilter->GetRawFilterText().ToString();
	if (FilterString.IsEmpty())
	{
		for (const auto& Property : SAkItemBoolProperties_Helpers::FullBoolPropertiesList)
		{
			PropertiesList.Add(MakeShareable(new FString(Property)));
		}
	}
	else
	{
		for (const auto& Property : SAkItemBoolProperties_Helpers::FullBoolPropertiesList)
		{
			if (Property.Contains(FilterString))
			{
				PropertiesList.Add(MakeShareable(new FString(Property)));
			}
		}
	}

	ListViewPtr->RequestListRefresh();
}

void SAkItemBoolProperties::ListSelectionChanged( TSharedPtr< FString > ItemProperty, ESelectInfo::Type /*SelectInfo*/ )
{
	if (OnSelectionChanged.IsBound())
		OnSelectionChanged.Execute(ItemProperty, ESelectInfo::OnMouseClick);
}

const TArray<TSharedPtr<FString>> SAkItemBoolProperties::GetSelectedProperties() const
{
	return ListViewPtr->GetSelectedItems();
}

const FString SAkItemBoolProperties::GetSearchText() const
{
	return SearchBoxFilter->GetRawFilterText().ToString();
}

const void SAkItemBoolProperties::SetSearchText(const FString& newText)
{
	SearchBoxPtr->SetText(FText::FromString(newText));
}

EActiveTimerReturnType SAkItemBoolProperties::SetFocusPostConstruct(double InCurrentTime, float InDeltaTime)
{
	FWidgetPath WidgetToFocusPath;
	FSlateApplication::Get().GeneratePathToWidgetUnchecked(SearchBoxPtr.ToSharedRef(), WidgetToFocusPath);
	FSlateApplication::Get().SetKeyboardFocus(WidgetToFocusPath, EFocusCause::SetDirectly);

	return EActiveTimerReturnType::Stop;
}
#undef LOCTEXT_NAMESPACE