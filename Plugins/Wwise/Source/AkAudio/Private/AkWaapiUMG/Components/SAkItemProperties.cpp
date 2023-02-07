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
	SAkItemProperties.cpp
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
 includes.
------------------------------------------------------------------------------------*/
#include "AkWaapiUMG/Components/SAkItemProperties.h"
#include "AkAudioDevice.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Input/SButton.h"
#include "Layout/WidgetPath.h"
#include "Misc/ScopedSlowTask.h"
#include "AkAudioStyle.h"
#include "Framework/Application/SlateApplication.h"

/*------------------------------------------------------------------------------------
Defines
------------------------------------------------------------------------------------*/
#define LOCTEXT_NAMESPACE "AkAudio"

DEFINE_LOG_CATEGORY(LogAkItemProperties);

/*------------------------------------------------------------------------------------
Statics and Globals
------------------------------------------------------------------------------------*/
namespace SAkItemProperties_Helpers
{
	static const FString FullPropertiesList[] =
	{
#if AK_WWISESDK_VERSION_MAJOR >= 2018
		TEXT("CenterPercentage"),
#endif
#if AK_WWISESDK_VERSION_MAJOR <= 2017
		TEXT("DivergenceCenter"),
#endif
		TEXT("GameAuxSendHPF"),
		TEXT("GameAuxSendLPF"),
		TEXT("GameAuxSendVolume"),
		TEXT("HdrActiveRange"),
		TEXT("HdrEnvelopeSensitivity"),
		TEXT("Highpass"),
		TEXT("InitialDelay"),
		TEXT("LoopCount"),
		TEXT("Lowpass"),
		TEXT("MakeUpGain"),
		TEXT("MaxSoundPerInstance"),
		TEXT("MidiChannelFilter"),
		TEXT("MidiKeyFilterMax"),
		TEXT("MidiKeyFilterMin"),
		TEXT("MidiTrackingRootNote"),
		TEXT("MidiTransposition"),
		TEXT("MidiVelocityFilterMax"),
		TEXT("MidiVelocityFilterMin"),
		TEXT("MidiVelocityOffset"),
#if AK_WWISESDK_VERSION_MAJOR <= 2017
		TEXT("MotionLowpass"),
		TEXT("MotionVolume"),
#endif
		TEXT("OutputBusHighpass"),
		TEXT("OutputBusLowpass"),
		TEXT("OutputBusVolume"),
		TEXT("Pitch"),
		TEXT("PreFetchLength"),
		TEXT("Priority"),
		TEXT("PriorityDistanceOffset"),
#if AK_WWISESDK_VERSION_MAJOR >= 2018
		TEXT("SpeakerPanning3DSpatializationMix"),
#endif
		TEXT("UserAuxSendVolume0"),
		TEXT("UserAuxSendVolume1"),
		TEXT("UserAuxSendVolume2"),
		TEXT("UserAuxSendVolume3"),
		TEXT("Volume"),
		TEXT("Weight")
	};

	enum { FullPropertiesListSize = sizeof(FullPropertiesList) / sizeof(*FullPropertiesList) };
}
/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------
Implementation
------------------------------------------------------------------------------------*/
SAkItemProperties::SAkItemProperties()
{}

SAkItemProperties::~SAkItemProperties()
{}

void SAkItemProperties::Construct(const FArguments& InArgs)
{
	OnDragDetected = InArgs._OnDragDetected;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	if (InArgs._FocusSearchBoxWhenOpened)
	{
		RegisterActiveTimer(0.f, FWidgetActiveTimerDelegate::CreateSP(this, &SAkItemProperties::SetFocusPostConstruct));
	}

	SearchBoxFilter = MakeShareable( new StringFilter( StringFilter::FItemToStringArray::CreateSP( this, &SAkItemProperties::PopulateSearchStrings ) ) );
	SearchBoxFilter->OnChanged().AddSP( this, &SAkItemProperties::FilterUpdated );
  
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
					.OnTextChanged( this, &SAkItemProperties::OnSearchBoxChanged )
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
				.OnGenerateRow( this, &SAkItemProperties::GenerateRow )
				.ItemHeight(18)
				.SelectionMode(InArgs._SelectionMode)
				.OnSelectionChanged(this, &SAkItemProperties::ListSelectionChanged)
				.ClearSelectionOnClick(false)
			]
		]
	];

	for (const auto& Property : SAkItemProperties_Helpers::FullPropertiesList)
	{
		PropertiesList.Add(MakeShareable(new FString(Property)));
	}

	ListViewPtr->RequestListRefresh();
}

TSharedRef<ITableRow> SAkItemProperties::GenerateRow( TSharedPtr<FString> ItemProperty, const TSharedRef<STableViewBase>& OwnerTable )
{
	check(ItemProperty.IsValid());
	
	TSharedPtr<ITableRow> NewRow = SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		.OnDragDetected(this, &SAkItemProperties::HandleOnDragDetected)
		[
			SNew(STextBlock)
			.Text(FText::FromString(*ItemProperty.Get()))
			.HighlightText(SearchBoxFilter.Get(), &StringFilter::GetRawFilterText)
		];
	return NewRow.ToSharedRef();
}

FReply SAkItemProperties::HandleOnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{		
	// Refresh the contents
	if(OnDragDetected.IsBound())
		return OnDragDetected.Execute(Geometry,MouseEvent);
	return FReply::Unhandled();
}

void SAkItemProperties::PopulateSearchStrings( const FString& PropertyName, OUT TArray< FString >& OutSearchStrings ) const
{
	OutSearchStrings.Add( PropertyName );
}

void SAkItemProperties::OnSearchBoxChanged( const FText& InSearchText )
{
	SearchBoxFilter->SetRawFilterText( InSearchText );
}

void SAkItemProperties::FilterUpdated()
{
	FScopedSlowTask SlowTask(2.f, LOCTEXT("AK_PopulatingPicker", "Populating Properties Picker..."));
	SlowTask.MakeDialog();

	PropertiesList.Empty(SAkItemProperties_Helpers::FullPropertiesListSize);

	const FString& FilterString = SearchBoxFilter->GetRawFilterText().ToString();
	if (FilterString.IsEmpty())
	{
		for (const auto& Property : SAkItemProperties_Helpers::FullPropertiesList)
		{
			PropertiesList.Add(MakeShareable(new FString(Property)));
		}
	}
	else
	{
		for (const auto& Property : SAkItemProperties_Helpers::FullPropertiesList)
		{
			if (Property.Contains(FilterString))
			{
				PropertiesList.Add(MakeShareable(new FString(Property)));
			}
		}
	}

	ListViewPtr->RequestListRefresh();
}

void SAkItemProperties::ListSelectionChanged( TSharedPtr< FString > ItemProperty, ESelectInfo::Type /*SelectInfo*/ )
{
	if (OnSelectionChanged.IsBound())
		OnSelectionChanged.Execute(ItemProperty, ESelectInfo::OnMouseClick);
}

const TArray<TSharedPtr<FString>> SAkItemProperties::GetSelectedProperties() const
{
	return ListViewPtr->GetSelectedItems();
}

const FString SAkItemProperties::GetSearchText() const
{
	return SearchBoxFilter->GetRawFilterText().ToString();
}

const void SAkItemProperties::SetSearchText(const FString& newText)
{
	SearchBoxPtr->SetText(FText::FromString(newText));
}

EActiveTimerReturnType SAkItemProperties::SetFocusPostConstruct(double InCurrentTime, float InDeltaTime)
{
	FWidgetPath WidgetToFocusPath;
	FSlateApplication::Get().GeneratePathToWidgetUnchecked(SearchBoxPtr.ToSharedRef(), WidgetToFocusPath);
	FSlateApplication::Get().SetKeyboardFocus(WidgetToFocusPath, EFocusCause::SetDirectly);

	return EActiveTimerReturnType::Stop;
}
#undef LOCTEXT_NAMESPACE