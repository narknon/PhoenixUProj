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


#include "MovieSceneAkAudioRTPCTrackEditor.h"
#include "AkAudioDevice.h"
#include "AkRtpc.h"

#include "MovieScene.h"
#include "MovieSceneCommonHelpers.h"
#include "MovieSceneAkAudioRTPCTrack.h"
#include "MovieSceneAkAudioRTPCSection.h"

#include "SequencerUtilities.h"
#include "ISequencerSection.h"
#include "ISequencerObjectChangeListener.h"
#include "ISectionLayoutBuilder.h"
#include "SequencerSectionPainter.h"

#include "AkAudioStyle.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

#include "ScopedTransaction.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"

#include "EditorStyleSet.h"
#include "Editor.h"

#define LOCTEXT_NAMESPACE "MovieSceneAkAudioRTPCTrackEditor"


/**
 * Class that draws a transform section in the sequencer
 */
class FMovieSceneAkAudioRTPCSection
	: public ISequencerSection
{
public:

	FMovieSceneAkAudioRTPCSection(UMovieSceneSection& InSection)
		: Section(Cast<UMovieSceneAkAudioRTPCSection>(&InSection))
	{ }

public:

	// ISequencerSection interface

	virtual UMovieSceneSection* GetSectionObject() override { return Section; }

	virtual FText GetSectionTitle() const override
	{
		return FText::FromString(Section->GetRTPCName());
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& InPainter) const override
	{
		return InPainter.PaintSectionBackground();
	}

private:

	/** The section we are visualizing */
	UMovieSceneAkAudioRTPCSection* Section;
};

FMovieSceneAkAudioRTPCTrackEditor::FMovieSceneAkAudioRTPCTrackEditor(TSharedRef<ISequencer> InSequencer)
	: FKeyframeTrackEditor<UMovieSceneAkAudioRTPCTrack>(InSequencer)
{
}

TSharedRef<ISequencerTrackEditor> FMovieSceneAkAudioRTPCTrackEditor::CreateTrackEditor(TSharedRef<ISequencer> InSequencer)
{
	return MakeShareable(new FMovieSceneAkAudioRTPCTrackEditor(InSequencer));
}

TSharedRef<ISequencerSection> FMovieSceneAkAudioRTPCTrackEditor::MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding)
{
	return MakeShareable(new FMovieSceneAkAudioRTPCSection(SectionObject));
}

const FSlateBrush* FMovieSceneAkAudioRTPCTrackEditor::GetIconBrush() const
{
	return FAkAudioStyle::Get().GetBrush("AudiokineticTools.RTPCIcon");
}



struct FRTPCSectionCreateDialogOptions
{
	FString RTPCName;
	UAkRtpc* RTPC = nullptr;
	bool OkClicked;

	FRTPCSectionCreateDialogOptions() : OkClicked(false) {}

	bool Validate()
	{
		// TODO: Verify that this RTPCName is a valid RTPC name!
		return OkClicked && (RTPC != nullptr || RTPCName.Len() > 0);
	}
};


class SCreateAkAudioRTPCSectionDialog
	: public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SCreateAkAudioRTPCSectionDialog) { }
	SLATE_END_ARGS()

	/** Construct this widget. */
	void Construct(const FArguments& InArgs, FRTPCSectionCreateDialogOptions& InOptions, TSharedRef<SWindow> InWindow)
	{
		Options = &InOptions;
		Window = InWindow;
		FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

		FAssetPickerConfig AssetPickerConfig;
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
		AssetPickerConfig.bAllowNullSelection = false;
		AssetPickerConfig.Filter.ClassNames.Add(UAkRtpc::StaticClass()->GetFName());
		AssetPickerConfig.OnAssetSelected = FOnAssetSelected::CreateLambda([&InOptions](const FAssetData& InRTPCAssetData) {
			if (InRTPCAssetData.IsValid())
			{
				InOptions.RTPC = CastChecked<UAkRtpc>(InRTPCAssetData.GetAsset());
			}
		});

		ChildSlot
		[
			SNew(SBorder)
			.Visibility(EVisibility::Visible)
			.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.VAlign(VAlign_Top)
				.Padding(4)
				[
					SNew(SBorder)
					.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
					.Padding(4.0f)
					.Content()
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 2, 6, 2)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("AkAudioRTPC", "RTPC"))
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0, 2, 0)
						[
							SNew(SBox)
							.WidthOverride(300.0f)
							.HeightOverride(300.f)
							[
								ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
							]
						]
					]
				]
				+ SVerticalBox::Slot()
				.FillHeight(1)
				.VAlign(VAlign_Top)
				.Padding(4)
				[
					SNew(SExpandableArea)
					.AreaTitle(LOCTEXT("Advanced", "Advanced"))
					.InitiallyCollapsed(true)
					.BodyContent()
					[
						SNew(SBorder)
						.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
						.Padding(4.0f)
						.Content()
						[
							SNew(SHorizontalBox)

							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2, 2, 6, 2)
							[
								SNew(STextBlock)
								.Text(LOCTEXT("AkAudioRTPCName", "RTPC Name"))
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(2, 0, 2, 0)
							[
								SNew(SEditableTextBox)
								.HintText(LOCTEXT("AkAudioRTPCNameHint", "Name of the AkAudioRTPC"))
								.OnTextCommitted(this, &SCreateAkAudioRTPCSectionDialog::OnEventNameCommited)
								.OnTextChanged(this, &SCreateAkAudioRTPCSectionDialog::OnEventNameCommited, ETextCommit::Default)
								.MinDesiredWidth(200)
								.RevertTextOnEscape(true)
							]
						]
					]
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Bottom)
				.Padding(8)
				[
					SNew(SUniformGridPanel)
					.SlotPadding(FEditorStyle::GetMargin("StandardDialog.SlotPadding"))
					.MinDesiredSlotWidth(FEditorStyle::GetFloat("StandardDialog.MinDesiredSlotWidth"))
					.MinDesiredSlotHeight(FEditorStyle::GetFloat("StandardDialog.MinDesiredSlotHeight"))

					+ SUniformGridPanel::Slot(0, 0)
					[
						SNew(SButton)
						.HAlign(HAlign_Center)
						.ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
						.OnClicked_Lambda([this]() -> FReply { CloseDialog(true); return FReply::Handled(); })
						.Text(LOCTEXT("OkButtonLabel", "OK"))
					]

					+ SUniformGridPanel::Slot(1, 0)
					[
						SNew(SButton)
						.HAlign(HAlign_Center)
						.ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
						.OnClicked_Lambda([this]() -> FReply { CloseDialog(false); return FReply::Handled(); })
						.Text(LOCTEXT("CancelButtonLabel", "Cancel"))
					]
				]
			]
		];
	}

protected:

	void CloseDialog(bool InOkClicked)
	{
		Options->OkClicked = InOkClicked;

		if (Window.IsValid())
		{
			Window.Pin()->RequestDestroyWindow();
		}
	}

private:

	void OnEventNameCommited(const FText& InText, ETextCommit::Type InCommitType)
	{
		Options->RTPCName = InText.ToString();

		if (InCommitType == ETextCommit::OnEnter || InCommitType == ETextCommit::OnCleared)
		{
			CloseDialog(InCommitType == ETextCommit::OnEnter);
		}
	}


	FRTPCSectionCreateDialogOptions* Options;
	TWeakPtr<SWindow> Window;
};


bool ConfigureRTPCSection(FRTPCSectionCreateDialogOptions& Options)
{
	TSharedRef<SWindow> Window = SNew(SWindow)
	.Title(LOCTEXT("CreateAkAudioRTPCSectionDialog", "Enter AkAudioRTPC Name"))
	.ClientSize(FVector2D(372, 418))
	.SupportsMinimize(false)
	.SupportsMaximize(false);

	Window->SetContent(SNew(SCreateAkAudioRTPCSectionDialog, Options, Window));
	GEditor->EditorAddModalWindow(Window);

	return Options.Validate();
}



void FMovieSceneAkAudioRTPCTrackEditor::TryAddAkAudioRTPCTrack(FCreateAkAudioRTPCTrack DoCreateAkAudioRTPCTrack)
{
	FRTPCSectionCreateDialogOptions Options;
	if (ConfigureRTPCSection(Options))
	{
		auto FocusedMovieScene = GetFocusedMovieScene();

		if (FocusedMovieScene == nullptr)
		{
			return;
		}

		const FScopedTransaction Transaction(LOCTEXT("AddAkAudioRTPCTrack_Transaction", "Add AkAudioRTPC Track"));
		FocusedMovieScene->Modify();

		auto NewTrack = DoCreateAkAudioRTPCTrack.Execute(FocusedMovieScene);
		ensure(NewTrack);

		auto NewSection = NewTrack->CreateNewSection();
		ensure(NewSection);

		auto RTPCSection = Cast<UMovieSceneAkAudioRTPCSection>(NewSection);
		ensure(RTPCSection);
		if (Options.RTPC)
		{
			RTPCSection->SetRTPC(Options.RTPC);
		}
		else
		{
			RTPCSection->SetRTPCName(Options.RTPCName);
		}

		NewSection->SetRange(TRange<FFrameNumber>::All());
		NewTrack->AddSection(*NewSection);

		GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
	}
}

void FMovieSceneAkAudioRTPCTrackEditor::BuildAddTrackMenu(FMenuBuilder& MenuBuilder)
{
	auto CreateAkAudioRTPCTrack = [=](UMovieScene* MovieScene)
	{
		auto NewTrack = MovieScene->AddMasterTrack<UMovieSceneAkAudioRTPCTrack>();
		if (NewTrack != nullptr)
		{
			NewTrack->SetIsAMasterTrack(true);
		}
		return NewTrack;
	};

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddAkAudioRTPCTrack", "AkAudioRTPC"),
		LOCTEXT("AddAkAudioRTPCMasterTrackTooltip", "Adds a master AkAudioRTPC track."),
		FSlateIcon(FAkAudioStyle::GetStyleSetName(), "AudiokineticTools.RTPCIcon"),
		FUIAction(FExecuteAction::CreateLambda([=]
		{
			TryAddAkAudioRTPCTrack(FCreateAkAudioRTPCTrack::CreateLambda(CreateAkAudioRTPCTrack));
		}))
	);
}

bool FMovieSceneAkAudioRTPCTrackEditor::SupportsSequence(UMovieSceneSequence* InSequence) const
{
	static UClass* LevelSequenceClass = FindObject<UClass>(ANY_PACKAGE, TEXT("LevelSequence"), true);
	return InSequence != nullptr && LevelSequenceClass != nullptr && InSequence->GetClass()->IsChildOf(LevelSequenceClass);
}


#if UE_4_23_OR_LATER
void FMovieSceneAkAudioRTPCTrackEditor::BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const TArray<FGuid>& ObjectBindings, const UClass* ObjectClass)
{
	auto ObjectBinding = ObjectBindings[0];
#else
void FMovieSceneAkAudioRTPCTrackEditor::BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const FGuid& ObjectBinding, const UClass* ObjectClass)
{
#endif
	if (!ObjectClass->IsChildOf(AActor::StaticClass()) && !ObjectClass->IsChildOf(USceneComponent::StaticClass()))
	{
		return;
	}

	auto CreateAkAudioRTPCTrack = [=](UMovieScene* MovieScene) { return MovieScene->AddTrack<UMovieSceneAkAudioRTPCTrack>(ObjectBinding); };

	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddAkAudioRTPCTrack", "AkAudioRTPC"),
		LOCTEXT("AddAkAudioRTPCTrackTooltip", "Adds an AkAudioRTPC track."),
		FSlateIcon(FAkAudioStyle::GetStyleSetName(), "AudiokineticTools.RTPCIcon"),
		FUIAction(FExecuteAction::CreateLambda([=]
		{
			TryAddAkAudioRTPCTrack(FCreateAkAudioRTPCTrack::CreateLambda(CreateAkAudioRTPCTrack));
		}))
	);
}

#undef LOCTEXT_NAMESPACE
