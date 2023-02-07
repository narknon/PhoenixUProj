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

#include "SAkGeometrySurfaceOverrideController.h"

#include "AkGeometryComponent.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "Editor/TransBuffer.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Input/SCheckBox.h"

namespace AkGeometryUI
{
	static int LabelWidth = 146;
}

void SSurfacePropertiesLabels::Construct(const FArguments& InArgs, FAkGeometrySurfaceOverride* InSurfaceOverride)
{
	SurfaceOverride = InSurfaceOverride;

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
					.WidthOverride(AkGeometryUI::LabelWidth)
					[
						SNew(STextBlock)
						.ToolTipText(FText::FromString("The Audiokinetic Texture associated with the surface."))
						.Text(FText::FromString(FString(TEXT("AkAcousticTexture"))))
						.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				]
			]
			+ SVerticalBox::Slot() // Transmission Loss
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Label
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(AkGeometryUI::LabelWidth)
					[
						SNew(STextBlock)
						.ToolTipText(FText::FromString("Indicates whether the surface overrides the transmission loss value."))
						.Text(FText::FromString(FString(TEXT("Override Transmission Loss"))))
						.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				]
			]
			+ SVerticalBox::Slot() // Enable Transmission Loss Override
			.FillHeight(0.33f)
			[
				SNew(SBox)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot() // Label
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(AkGeometryUI::LabelWidth)
						.Visibility_Lambda([this]() { return TransmissionLossVisibility(); })
						[
							SNew(STextBlock)
							.ToolTipText(FText::FromString("Indicates how much sound is transmitted through the surface."))
							.Text(FText::FromString(FString(TEXT("Transmission Loss"))))
							.Font(IDetailLayoutBuilder::GetDetailFont())
						]
					]
				]
			]
		]
	];
}

EVisibility SSurfacePropertiesLabels::TransmissionLossVisibility() const
{
	if (SurfaceOverride == nullptr)
		return EVisibility::Visible;
	return SurfaceOverride->bEnableOcclusionOverride ? EVisibility::Visible : EVisibility::Collapsed;
}

// ==================================================
// SAkGeometrySurfaceController
// ==================================================

void SAkGeometrySurfaceController::Construct(const FArguments& InArgs, TWeakObjectPtr<UObject> ObjectBeingCustomized, IDetailLayoutBuilder* InLayoutBuilder)
{
	LayoutBuilder = InLayoutBuilder;
	ComponentBeingCustomized = Cast<UAkGeometryComponent>(ObjectBeingCustomized);
	BuildSlate();
}

SAkGeometrySurfaceController::~SAkGeometrySurfaceController()
{

}

void SAkGeometrySurfaceController::BeginModify(FText TransactionText)
{
	if (GEditor && GEditor->Trans)
	{
		UTransBuffer* TransBuffer = CastChecked<UTransBuffer>(GEditor->Trans);
		if (TransBuffer != nullptr)
			TransBuffer->Begin(*FString("AkGeometry Acoustic Surfaces"), TransactionText);
	}

	if (ComponentBeingCustomized != nullptr)
		ComponentBeingCustomized->Modify();
}

void SAkGeometrySurfaceController::EndModify()
{
	if (GEditor && GEditor->Trans)
	{
		UTransBuffer* TransBuffer = CastChecked<UTransBuffer>(GEditor->Trans);
		if (TransBuffer != nullptr)
			TransBuffer->End();
	}
}

FString SAkGeometrySurfaceController::GetSelectedTextureAssetPath() const
{
	FAkGeometrySurfaceOverride* SurfaceProperties = GetSurfaceOverride();
	if (SurfaceProperties == nullptr)
		return "";

	FSoftObjectPath Path(SurfaceProperties->AcousticTexture);
	return Path.GetAssetPathString();
}

void SAkGeometrySurfaceController::OnTextureAssetChanged(const FAssetData& InAssetData)
{
	BeginModify(FText::FromString(FString("Set AkGeometry Texture")));

	FAkGeometrySurfaceOverride* SurfaceProperties = GetSurfaceOverride();
	if (SurfaceProperties != nullptr)
	{
		SurfaceProperties->AcousticTexture = Cast<UAkAcousticTexture>(InAssetData.GetAsset());
	}

	EndModify();
}

TOptional<float> SAkGeometrySurfaceController::GetTransmissionLossValue() const
{
	if (GetSurfaceOverride() != nullptr)
		return GetSurfaceOverride()->OcclusionValue;
	return 0.0f;
}

void SAkGeometrySurfaceController::OnTransmissionLossChanged(float NewValue, ETextCommit::Type Commit)
{
	// Only apply valid values
	if (NewValue >= 0.0f && NewValue <= 1.0f)
	{
		if (GetSurfaceOverride() != nullptr)
		{
			BeginModify(FText::FromString(FString("AkGeometry: Set Transmission Loss Value")));
			GetSurfaceOverride()->OcclusionValue = NewValue;
			EndModify();
		}
	}
}

EVisibility SAkGeometrySurfaceController::TransmissionLossVisibility() const
{
	if (GetSurfaceOverride() == nullptr)
		return EVisibility::Visible;
	return GetSurfaceOverride()->bEnableOcclusionOverride ? EVisibility::Visible : EVisibility::Collapsed;
}

ECheckBoxState SAkGeometrySurfaceController::GetEnableTransmissionLossOverrideCheckBoxState() const
{
	if (GetSurfaceOverride() == nullptr)
		return ECheckBoxState::Undetermined;
	bool bEnabled = GetSurfaceOverride()->bEnableOcclusionOverride;
	return bEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SAkGeometrySurfaceController::OnEnableTransmissionLossOverrideChanged(ECheckBoxState NewState)
{
	if (GetSurfaceOverride() != nullptr)
	{
		bool bEnable = NewState == ECheckBoxState::Checked;
		FString ModifyString = bEnable ? "AkGeometry: Enable Transmission Loss Override"
									   : "AkGeometry: Disable Transmission Loss Override";
		BeginModify(FText::FromString(ModifyString));
		GetSurfaceOverride()->bEnableOcclusionOverride = bEnable;
		EndModify();
	}
}

void SAkGeometrySurfaceController::BuildSlate()
{
	FSlateFontInfo selectionInfoFont = LayoutBuilder != nullptr ? LayoutBuilder->GetDetailFontItalic() : FEditorStyle::GetFontStyle("TinyText");

	ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot() // Controls
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
						.OnObjectChanged(this, &SAkGeometrySurfaceController::OnTextureAssetChanged)
						.ObjectPath(this, &SAkGeometrySurfaceController::GetSelectedTextureAssetPath)
						.ToolTipText(FText::FromString("The Audiokinetic Texture associated with the surface."))
					]
				]
			]
			+ SVerticalBox::Slot() // Enable Transmission Loss Override
			.FillHeight(0.33f)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot() // Control
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SCheckBox)
					.OnCheckStateChanged(this, &SAkGeometrySurfaceController::OnEnableTransmissionLossOverrideChanged)
					.IsChecked(this, &SAkGeometrySurfaceController::GetEnableTransmissionLossOverrideCheckBoxState)
					.ToolTipText(FText::FromString("Indicates whether the surface overrides the transmission loss value."))
				]
			]
			+ SVerticalBox::Slot() // Transmission Loss
			.FillHeight(0.33f)
			[
				SNew(SBox)
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
							.Visibility_Lambda([this]() { return TransmissionLossVisibility(); })
							[
								SNew(SNumericEntryBox<float>)
								.MinValue(0.0f)
								.MaxValue(1.0f)
								.MinSliderValue(0.0f)
								.MaxSliderValue(1.0f)
								.ToolTipText(FText::FromString("Indicates how much sound is transmitted through the surface."))
								.Value(this, &SAkGeometrySurfaceController::GetTransmissionLossValue)
								.OnValueCommitted(this, &SAkGeometrySurfaceController::OnTransmissionLossChanged)
							]
						]
					]
				]
			]
		]
		+ SHorizontalBox::Slot() // Labels
		.AutoWidth()
		[
			SNew(SSurfacePropertiesLabels, GetSurfaceOverride())
		]
	];
}

FAkGeometrySurfaceOverride* SAkGeometryCollisionMeshSurfaceController::GetSurfaceOverride() const
{
	if (ComponentBeingCustomized == nullptr)
		return nullptr;
	return &(ComponentBeingCustomized->CollisionMeshSurfaceOverride);
}

void SAkGeometryStaticMeshSurfaceController::Construct(const FArguments& InArgs, TWeakObjectPtr<UObject> ObjectBeingCustomized, IDetailLayoutBuilder* InLayoutBuilder, UMaterialInterface* InMaterialKey)
{
	MaterialKey = InMaterialKey;
	SAkGeometrySurfaceController::Construct(InArgs, ObjectBeingCustomized, InLayoutBuilder);
}

FAkGeometrySurfaceOverride* SAkGeometryStaticMeshSurfaceController::GetSurfaceOverride() const
{
	if (ComponentBeingCustomized == nullptr)
		return nullptr;
	return ComponentBeingCustomized->StaticMeshSurfaceOverride.Find(MaterialKey);
}