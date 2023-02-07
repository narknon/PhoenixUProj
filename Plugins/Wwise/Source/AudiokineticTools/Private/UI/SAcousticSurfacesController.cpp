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

#include "SAcousticSurfacesController.h"

#include "AkSurfaceReflectorSetComponent.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "EditorModeManager.h"
#include "EditorModes.h"
#include "Engine/Selection.h"
#include "Editor/TransBuffer.h"
#include "EditorStyleSet.h"
#include "EditorSupportDelegates.h"
#include "PropertyCustomizationHelpers.h"
#include "SlateCore/Public/Widgets/SBoxPanel.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

#if AK_SUPPORT_WAAPI
#include "AkWaapiClient.h"
#include "AkWaapiUtils.h"
#include "Async/Async.h"
#endif

#define LOCTEXT_NAMESPACE "AkAudio"

namespace AkAcousticSurfacesUI
{
	static FText OverrideButtonText = FText::FromString(FString("Override"));
	static int OverrideButtonPadding = 5;
	static int LabelWidth = 102;
}

class SOverrideControls : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SOverrideControls) {}
		/** Called when the button is clicked */
		SLATE_EVENT(FOnClicked, OnButtonClicked)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		OnButtonClicked = InArgs._OnButtonClicked;

		ChildSlot
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot() // Label
			.AutoWidth()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString(FString(TEXT("Multiple Values"))))
			]
			+ SHorizontalBox::Slot() // Button
			.AutoWidth()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(AkAcousticSurfacesUI::OverrideButtonPadding, 0)
			[
				SNew(SButton)
				.Text(AkAcousticSurfacesUI::OverrideButtonText)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.OnClicked(this, &SOverrideControls::CallClicked)
			]
		];
	}

private:
	FOnClicked OnButtonClicked;
	FReply CallClicked() { return OnButtonClicked.Execute(); }
};

// ==================================================
// SAcousticSurfacesLabels
// ==================================================

void SAcousticSurfacesLabels::Construct(const FArguments& InArgs, TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized)
{
	ComponentsBeingCustomized = ObjectsBeingCustomized;

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot() // Acoustic Surface Parameters
		.FillHeight(1.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot() // Texture
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Label
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(AkAcousticSurfacesUI::LabelWidth)
					[
						SNew(STextBlock)
						.ToolTipText(FText::FromString("The Audiokinetic Texture associated with the selected faces."))
						.Text(FText::FromString(FString(TEXT("AkAcousticTexture"))))
						.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				]
			]
			+ SVerticalBox::Slot() // Occlusion
			.FillHeight(0.33f)
			[
				SNew(SBox)
				.Visibility_Lambda([this]() { return TransmissionLossEnableSurfaceVisibility(); })
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot() // Label
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(AkAcousticSurfacesUI::LabelWidth)
						[
							SNew(STextBlock)
							.ToolTipText(FText::FromString("Indicates how much sound is transmitted through the surface."))
							.Text(FText::FromString(FString(TEXT("Transmission Loss"))))
							.Font(IDetailLayoutBuilder::GetDetailFont())
						]
					]
				]
			]
			+ SVerticalBox::Slot() // EnableSurface
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Label
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(AkAcousticSurfacesUI::LabelWidth)
					[
						SNew(STextBlock)
						.ToolTipText(FText::FromString("Indicates whether the selected faces are sent to the Spatial Audio engine."))
						.Text(FText::FromString(FString(TEXT("Enable Surface"))))
						.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				]
			]
		]
	];
}

EVisibility SAcousticSurfacesLabels::TransmissionLossEnableSurfaceVisibility()
{
	for (TWeakObjectPtr<UObject> ObjectBeingCustomized : ComponentsBeingCustomized)
	{
		UAkSurfaceReflectorSetComponent* reflectorSetComponent = Cast<UAkSurfaceReflectorSetComponent>(ObjectBeingCustomized.Get());
		if (reflectorSetComponent && reflectorSetComponent->bEnableSurfaceReflectors)
		{
			return EVisibility::Visible;
		}
	}
	return EVisibility::Collapsed;
}

// ==================================================
// SAcousticSurfacesController
// ==================================================

void SAcousticSurfacesController::Construct(const FArguments& InArgs, TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized, IDetailLayoutBuilder* InLayoutBuilder)
{
	ensure(ObjectsBeingCustomized.Num() > 0);

	LayoutBuilder = InLayoutBuilder;

	FCoreUObjectDelegates::FOnObjectPropertyChanged::FDelegate OnPropertyChangedDelegate = FCoreUObjectDelegates::FOnObjectPropertyChanged::FDelegate::CreateRaw(this, &SAcousticSurfacesController::OnPropertyChanged);
	OnPropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.Add(OnPropertyChangedDelegate);

	GLevelEditorModeTools().OnEditorModeIDChanged().AddRaw(this, &SAcousticSurfacesController::OnEditorModeChanged);

	ComponentsToEdit = ObjectsBeingCustomized;

	if (GLevelEditorModeTools().IsModeActive(FEditorModeID(TEXT("EM_Geometry"))))
	{
		// In geometry edit mode, we only want to apply to all faces when no individual faces are selected.
		bool individualSelection = false;
		// Loop through all selected components to check if any indivdual faces are selected.
		// If no individual faces are selected, we'll just apply the changes to every face on each component.
		for (TWeakObjectPtr<UObject> ObjectBeingCustomized : ComponentsToEdit)
		{
			UAkSurfaceReflectorSetComponent* reflectorSetComponent = Cast<UAkSurfaceReflectorSetComponent>(ObjectBeingCustomized.Get());
			if (reflectorSetComponent)
			{
				TSet<int> FacesToEdit = reflectorSetComponent->GetSelectedFaceIndices();
				if (FacesToEdit.Num() > 0)
				{
					individualSelection = true;
					break;
				}
			}
		}
		ApplyToAllFaces = !individualSelection;
	}
	else
	{
		ApplyToAllFaces = true;
	}

	InitReflectorSetsFacesToEdit();
	UpdateCurrentValues();
	RegisterTextureDeletedCallback();

	BuildSlate();
}

SAcousticSurfacesController::~SAcousticSurfacesController()
{
	RemoveTextureDeletedCallback();
	FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(OnPropertyChangedHandle);
	GLevelEditorModeTools().OnEditorModeIDChanged().RemoveAll(this);
}

void SAcousticSurfacesController::InitReflectorSetsFacesToEdit()
{
	NumFacesSelected = 0;
	for (TWeakObjectPtr<UObject> ObjectBeingCustomized : ComponentsToEdit)
	{
		UAkSurfaceReflectorSetComponent* reflectorSetComponent = Cast<UAkSurfaceReflectorSetComponent>(ObjectBeingCustomized.Get());
		if (reflectorSetComponent)
		{
			TSet<int> FacesToEdit;
			if (ApplyToAllFaces)
			{
				for (int i = 0; i < reflectorSetComponent->AcousticPolys.Num(); ++i)
					FacesToEdit.Add(i);
			}
			else
			{
				FacesToEdit = reflectorSetComponent->GetSelectedFaceIndices();
			}
			NumFacesSelected += FacesToEdit.Num();
			if (FacesToEdit.Num() > 0)
				ReflectorSetsFacesToEdit.Add(reflectorSetComponent, FacesToEdit);
		}
	}

	UpdateCurrentValues();
}

FAkSurfacePoly& SAcousticSurfacesController::GetAcousticSurfaceChecked(UAkSurfaceReflectorSetComponent* reflectorSet, int faceIndex)
{
	ensure(faceIndex <= reflectorSet->AcousticPolys.Num());
	return reflectorSet->AcousticPolys[faceIndex];
}

void SAcousticSurfacesController::RefreshEditor(bool reinitVisualizers /*= false*/) const
{
	FEditorSupportDelegates::RedrawAllViewports.Broadcast();

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
		{
			if (reinitVisualizers)
			{
				ReflectorSetComponent->CacheAcousticProperties();
				ReflectorSetComponent->UpdatePolys();
			}
			else
			{
				ReflectorSetComponent->SurfacePropertiesChanged();
			}
		}
	}

	if (LayoutBuilder != nullptr)
		LayoutBuilder->ForceRefreshDetails();
}

void SAcousticSurfacesController::BeginModify(FText TransactionText)
{
	if (GEditor && GEditor->Trans)
	{
		UTransBuffer* TransBuffer = CastChecked<UTransBuffer>(GEditor->Trans);
		if (TransBuffer != nullptr)
			TransBuffer->Begin(*FString("AkSurfaceReflectorSet Acoustic Surfaces"), TransactionText);
	}

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
			ReflectorSetComponent->Modify();
	}		
}

void SAcousticSurfacesController::EndModify()
{
	if (GEditor && GEditor->Trans)
	{
		UTransBuffer* TransBuffer = CastChecked<UTransBuffer>(GEditor->Trans);
		if (TransBuffer != nullptr)
			TransBuffer->End();
	}
}

void SAcousticSurfacesController::OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent)
{
	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ObjectBeingModified == ReflectorSetComponent)
		{
			const FName memberPropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;
			if (memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSurfaceReflectorSetComponent, AcousticPolys))
			{
				UpdateCurrentValues();
			}
			return;
		}
	}
}

void SAcousticSurfacesController::OnEditorModeChanged(const FEditorModeID& InEditorModeID, bool bIsEnteringMode)
{
	if (InEditorModeID == FEditorModeID(TEXT("EM_Geometry")))
	{
		if (bIsEnteringMode)
		{
			ApplyToAllFaces = false;
			InitReflectorSetsFacesToEdit();
			Invalidate(EInvalidateWidgetReason::Paint);
		}
		else
		{
			ApplyToAllFaces = true;
			InitReflectorSetsFacesToEdit();
			Invalidate(EInvalidateWidgetReason::Paint);
		}
	}
}

FText SAcousticSurfacesController::GetSelectionText() const
{
	FString selectionInfo = "(All faces)";
	if (!ApplyToAllFaces && NumFacesSelected > 0)
	{
		selectionInfo = "(" + FString::FromInt(NumFacesSelected) + " faces selected)";
	}
	return FText::FromString(selectionInfo);
}

FText SAcousticSurfacesController::GetSelectionTextTooltip() const
{
	if (!ApplyToAllFaces && NumFacesSelected > 0)
	{
		return FText::FromString(FString("Changes will apply to all selected faces."));
	}
	return FText::FromString(FString("Changes will apply to all faces. Use ") + GEOMETRY_EDIT_DISPLAY_NAME + " to select individual faces. You can enable " GEOMETRY_EDIT_DISPLAY_NAME " by clicking 'Enable Edit Surfaces'.");
}

void SAcousticSurfacesController::UpdateCurrentValues()
{
	CurrentTexture = GetCollectiveTexture(TexturesDiffer);
	CurrentOcclusion = GetCollectiveOcclusion(OcclusionsDiffer);
	CurrentEnablement = GetCollectiveEnableSurface(EnablementsDiffer);
}

void SAcousticSurfacesController::OnTextureAssetChanged(const FAssetData& InAssetData)
{
	BeginModify(FText::FromString(FString("Set Textures")));

	CurrentTexture = Cast<UAkAcousticTexture>(InAssetData.GetAsset());

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = elem.Value;
			for (const int& i : FacesToEdit)
			{
				GetAcousticSurfaceChecked(ReflectorSetComponent, i).Texture = CurrentTexture;
			}
		}
	}

	RefreshEditor();

	EndModify();
}

FString SAcousticSurfacesController::GetSelectedTextureAssetPath() const
{
	if (CurrentTexture == nullptr)
	{
		return "";
	}
	
	FSoftObjectPath path(CurrentTexture);
	return path.GetAssetPathString();
}

EVisibility SAcousticSurfacesController::TransmissionLossEnableSurfaceVisibility()
{
	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr && ReflectorSetComponent->bEnableSurfaceReflectors)
			return EVisibility::Visible;
	}
	return EVisibility::Collapsed;
}

EVisibility SAcousticSurfacesController::OverrideTextureControlsVisibility()
{
	if (TexturesDiffer)
		return EVisibility::Visible;

	return EVisibility::Collapsed;
}

FReply SAcousticSurfacesController::OnOverrideTextureButtonClicked()
{
	BeginModify(FText::FromString(FString("Override Textures")));

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = elem.Value;
			for (const int& i : FacesToEdit)
			{
				GetAcousticSurfaceChecked(ReflectorSetComponent, i).Texture = nullptr;
			}
		}
	}

	RefreshEditor();

	EndModify();

	return FReply::Handled();
}

UAkAcousticTexture* SAcousticSurfacesController::GetCollectiveTexture(bool& ValuesDiffer)
{
	ValuesDiffer = false;

	if (ReflectorSetsFacesToEdit.Num() == 0)
		return nullptr;

	auto it = ReflectorSetsFacesToEdit.CreateIterator();
	ensure(it.Key() != nullptr);
	int firstIndex = *(it.Value().begin());
	UAkAcousticTexture* texture = it.Key()->AcousticPolys[firstIndex].Texture;

	for (; it; ++it)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = it.Key();
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = it.Value();
			for (const int& i : FacesToEdit)
			{
				if (GetAcousticSurfaceChecked(ReflectorSetComponent, i).Texture != texture)
				{
					ValuesDiffer = true;
					texture = nullptr;
					break;
				}
			}
		}
	}

	return texture;
}

EVisibility SAcousticSurfacesController::OverrideOcclusionControlsVisibility()
{
	return OcclusionsDiffer ? EVisibility::Visible : EVisibility::Collapsed;
}

FReply SAcousticSurfacesController::OnOverrideOcclusionButtonClicked()
{
	BeginModify(FText::FromString(FString("Override Transmission Loss Values")));

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = elem.Value;
			for (const int& i : FacesToEdit)
			{
				GetAcousticSurfaceChecked(ReflectorSetComponent, i).Occlusion = 0.0f;
			}
		}
	}

	RefreshEditor();

	EndModify();

	return FReply::Handled();
}

float SAcousticSurfacesController::GetCollectiveOcclusion(bool& ValuesDiffer)
{
	ValuesDiffer = false;
	if (ReflectorSetsFacesToEdit.Num() == 0)
		return 0.0f;

	auto it = ReflectorSetsFacesToEdit.CreateIterator();
	ensure(it.Key() != nullptr);
	int firstIndex = *(it.Value().begin());
	float occlusion = it.Key()->AcousticPolys[firstIndex].Occlusion;

	for (; it; ++it)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = it.Key();
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = it.Value();
			for (const int& i : FacesToEdit)
			{
				if (GetAcousticSurfaceChecked(ReflectorSetComponent, i).Occlusion != occlusion)
				{
					ValuesDiffer = true;
					occlusion = 0.0f;
					break;
				}
			}
		}
	}

	return occlusion;
}

TOptional<float> SAcousticSurfacesController::GetOcclusionSliderValue() const
{
	return CurrentOcclusion;
}

void SAcousticSurfacesController::OnOcclusionSliderChanged(float NewValue, ETextCommit::Type Commit)
{
	// Only apply valid values
	if (NewValue >= 0.0f && NewValue <= 1.0f)
	{
		BeginModify(FText::FromString(FString("Set Transmission Loss Values")));

		for (auto elem : ReflectorSetsFacesToEdit)
		{
			UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
			if (ReflectorSetComponent != nullptr)
			{
				TSet<int> FacesToEdit = elem.Value;
				for (const int& i : FacesToEdit)
				{
					GetAcousticSurfaceChecked(ReflectorSetComponent, i).Occlusion = NewValue;
				}
			}
		}

		RefreshEditor();

		EndModify();
	}
}

bool SAcousticSurfacesController::GetCollectiveEnableSurface(bool& ValuesDiffer)
{
	ValuesDiffer = false;
	if (ReflectorSetsFacesToEdit.Num() == 0)
		return false;

	auto it = ReflectorSetsFacesToEdit.CreateIterator();
	ensure(it.Key() != nullptr);
	int firstIndex = *(it.Value().begin());
	bool enableSurface = it.Key()->AcousticPolys[firstIndex].EnableSurface;

	for (; it; ++it)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = it.Key();
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = it.Value();
			for (const int& i : FacesToEdit)
			{
				if (GetAcousticSurfaceChecked(ReflectorSetComponent, i).EnableSurface != enableSurface)
				{
					ValuesDiffer = true;
					enableSurface = false;
					break;
				}
			}
		}
	}

	return enableSurface;
}

ECheckBoxState SAcousticSurfacesController::GetEnableSurfaceCheckBoxState() const
{
	return EnablementsDiffer ? ECheckBoxState::Undetermined 
							 : (CurrentEnablement ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
}

void SAcousticSurfacesController::OnEnableCheckboxChanged(ECheckBoxState NewState)
{
	BeginModify(FText::FromString(FString("Set Enable Surfaces")));

	for (auto elem : ReflectorSetsFacesToEdit)
	{
		UAkSurfaceReflectorSetComponent* ReflectorSetComponent = elem.Key;
		if (ReflectorSetComponent != nullptr)
		{
			TSet<int> FacesToEdit = elem.Value;
			if (NewState != ECheckBoxState::Undetermined)
			{
				bool enable = NewState == ECheckBoxState::Checked;
				for (const int& i : FacesToEdit)
				{
					GetAcousticSurfaceChecked(ReflectorSetComponent, i).EnableSurface = enable;
				}
			}
		}
	}

	RefreshEditor(true);

	EndModify();
}

#if AK_SUPPORT_WAAPI
void SAcousticSurfacesController::RegisterTextureDeletedCallback()
{
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
	if (waapiClient != nullptr && waapiClient->IsConnected())
	{
		auto textureDeletedCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> jsonObject)
		{
			const TSharedPtr<FJsonObject> itemObj = jsonObject->GetObjectField(WwiseWaapiHelper::OBJECT);
			if (itemObj != nullptr)
			{
				const FString itemIdString = itemObj->GetStringField(WwiseWaapiHelper::ID);
				FGuid itemID = FGuid::NewGuid();
				FGuid::ParseExact(itemIdString, EGuidFormats::DigitsWithHyphensInBraces, itemID);
				if (CurrentTexture != nullptr && itemID == CurrentTexture->ID)
				{
					AsyncTask(ENamedThreads::GameThread, [this, itemID]
					{
						CurrentTexture = nullptr;
					});
				}
			}
		});

		TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());
		options->SetArrayField(WwiseWaapiHelper::RETURN, TArray<TSharedPtr<FJsonValue>> { MakeShareable(new FJsonValueString(WwiseWaapiHelper::ID)) });
		TSharedPtr<FJsonObject> outJsonResult;
		if (!waapiClient->Subscribe(ak::wwise::core::object::preDeleted, options, textureDeletedCallback, TextureDeleteSubscriptionID, outJsonResult))
		{
			UE_LOG(LogAkAudio, Warning, TEXT("AkSettings: WAAPI: Acoustic texture object preDeleted subscription failed."));
		}
	}
}

void SAcousticSurfacesController::RemoveTextureDeletedCallback()
{
	FAkWaapiClient* waapiClient = FAkWaapiClient::Get();
	if (waapiClient != nullptr && waapiClient->IsConnected() && TextureDeleteSubscriptionID != 0)
	{
		TSharedPtr<FJsonObject> unsubscribeResult;
		waapiClient->Unsubscribe(TextureDeleteSubscriptionID, unsubscribeResult);
	}
}
#endif

void SAcousticSurfacesController::BuildSlate()
{
	FSlateFontInfo selectionInfoFont = LayoutBuilder != nullptr ? LayoutBuilder->GetDetailFontItalic() : FEditorStyle::GetFontStyle("TinyText");

	ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot() // Acoustic Surface Parameters
		.AutoWidth()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot() // Texture
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Control
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SObjectPropertyEntryBox)
						.AllowedClass(UAkAcousticTexture::StaticClass())
						.OnObjectChanged(this, &SAcousticSurfacesController::OnTextureAssetChanged)
						.ObjectPath(this, &SAcousticSurfacesController::GetSelectedTextureAssetPath)
						.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
						.Visibility_Lambda([this]() { return (OverrideTextureControlsVisibility() == EVisibility::Collapsed) ? EVisibility::Visible : EVisibility::Collapsed; })
					]
					+ SOverlay::Slot() // Multiple values controls
					[
						SNew(SBox)
						.Visibility_Lambda([this]() { return OverrideTextureControlsVisibility(); })
						[
							SNew(SOverrideControls)
							.OnButtonClicked(this, &SAcousticSurfacesController::OnOverrideTextureButtonClicked)
							.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
						]
					]
				]
			]
			+ SVerticalBox::Slot() // Occlusion
			.FillHeight(0.33f)
			[
				SNew(SBox)
				.Visibility_Lambda([this]() { return TransmissionLossEnableSurfaceVisibility(); })
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot() // Control
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					.AutoWidth()
					[
						SNew(SOverlay)
						+ SOverlay::Slot()
						[
							SNew(SBox)
							.Visibility_Lambda([this]() { return (OverrideOcclusionControlsVisibility() == EVisibility::Collapsed) ? EVisibility::Visible : EVisibility::Collapsed; })
							[
								SNew(SNumericEntryBox<float>)
								.MinValue(0.0f)
								.MaxValue(1.0f)
								.MinSliderValue(0.0f)
								.MaxSliderValue(1.0f)
								.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
								.Value(this, &SAcousticSurfacesController::GetOcclusionSliderValue)
								.OnValueCommitted(this, &SAcousticSurfacesController::OnOcclusionSliderChanged)
							]
						]
						+ SOverlay::Slot() // Multiple values controls
						[
							SNew(SBox)
							.Visibility_Lambda([this]() { return OverrideOcclusionControlsVisibility(); })
							[
								SNew(SOverrideControls)
								.OnButtonClicked(this, &SAcousticSurfacesController::OnOverrideOcclusionButtonClicked)
								.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
							]
						]
					]
				]
			]
			+ SVerticalBox::Slot() // EnableSurface
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Control
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SCheckBox)
					.IsChecked(ECheckBoxState::Undetermined)
					.OnCheckStateChanged(this, &SAcousticSurfacesController::OnEnableCheckboxChanged)
					.IsChecked(this, &SAcousticSurfacesController::GetEnableSurfaceCheckBoxState)
					.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
				]
			]
		]
		+ SHorizontalBox::Slot() // Selection Info
		.AutoWidth()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot() // Texture
			.FillHeight(0.33f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(this, &SAcousticSurfacesController::GetSelectionText)
				.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
				.Font(selectionInfoFont)
			]
			+ SVerticalBox::Slot() // Occlusion
			.FillHeight(0.33f)
			[
				SNew(SBox)
				.Visibility_Lambda([this]() { return TransmissionLossEnableSurfaceVisibility(); })
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(this, &SAcousticSurfacesController::GetSelectionText)
					.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
					.Font(selectionInfoFont)
				]
			]
			+ SVerticalBox::Slot() // EnableSurface
			.FillHeight(0.33f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(this, &SAcousticSurfacesController::GetSelectionText)
				.ToolTipText(this, &SAcousticSurfacesController::GetSelectionTextTooltip)
				.Font(selectionInfoFont)
			]
		]
	];
}