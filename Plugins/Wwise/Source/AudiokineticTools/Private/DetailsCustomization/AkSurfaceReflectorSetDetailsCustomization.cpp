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

#include "AkSurfaceReflectorSetDetailsCustomization.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "AkComponent.h"
#include "UI/SAcousticSurfacesController.h"

#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "EditorModeManager.h"
#include "EditorSupportDelegates.h"
#include "IPropertyUtilities.h"
#include "LevelEditorActions.h"
#include "ScopedTransaction.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SExpanderArrow.h"
#include "Widgets/Input/SButton.h"
#include "GameFramework/Volume.h"

#include "Builders/ConeBuilder.h"
#include "Builders/CubeBuilder.h"
#include "Builders/CurvedStairBuilder.h"
#include "Builders/CylinderBuilder.h"
#include "Builders/LinearStairBuilder.h"
#include "Builders/SpiralStairBuilder.h"
#include "Builders/TetrahedronBuilder.h"

#include "Model.h"

#define LOCTEXT_NAMESPACE "AudiokineticTools"


//////////////////////////////////////////////////////////////////////////
// FAkSurfaceReflectorSetDetailsCustomization

FAkSurfaceReflectorSetDetailsCustomization::FAkSurfaceReflectorSetDetailsCustomization()
{
	ReflectorSetBeingCustomized = nullptr;
	FCoreUObjectDelegates::OnObjectModified.AddRaw(this, &FAkSurfaceReflectorSetDetailsCustomization::OnObjectModified);
	FEditorSupportDelegates::RedrawAllViewports.AddRaw(this, &FAkSurfaceReflectorSetDetailsCustomization::OnRedrawViewports);
}

FAkSurfaceReflectorSetDetailsCustomization::~FAkSurfaceReflectorSetDetailsCustomization()
{
	FCoreUObjectDelegates::OnObjectModified.RemoveAll(this);
	FEditorSupportDelegates::RedrawAllViewports.RemoveAll(this);

	if (ReflectorSetBeingCustomized && ReflectorSetBeingCustomized->IsValidLowLevelFast() && ReflectorSetBeingCustomized->GetOnRefreshDetails() )
	{
		if (ReflectorSetBeingCustomized->GetOnRefreshDetails()->IsBoundToObject(this))
		{
			ReflectorSetBeingCustomized->ClearOnRefreshDetails();
		}
		ReflectorSetBeingCustomized = nullptr;
	}
}

FReply FAkSurfaceReflectorSetDetailsCustomization::OnEnableEditModeClicked()
{
	FLevelEditorActionCallbacks::OnShowOnlySelectedActors();
	GLevelEditorModeTools().ActivateMode(FEditorModeID(TEXT("EM_Geometry")), false);
	return FReply::Handled();
}

FReply FAkSurfaceReflectorSetDetailsCustomization::OnDisableEditModeClicked()
{
	GLevelEditorModeTools().DeactivateMode(FEditorModeID(TEXT("EM_Geometry")));
	FLevelEditorActionCallbacks::ExecuteExecCommand(FString(TEXT("ACTOR UNHIDE ALL")));
	return FReply::Handled();
}

void FAkSurfaceReflectorSetDetailsCustomization::OnObjectModified(UObject* Object)
{
	if (!SelectedObjectModifiedThisFrame)
	{
		for (TWeakObjectPtr<UObject> UObjectPtr : ObjectsBeingCustomized)
		{
			if (Object == UObjectPtr.Get())
			{
				SelectedObjectModifiedThisFrame = true;
				return;
			}
		}
	}
}

void FAkSurfaceReflectorSetDetailsCustomization::OnRedrawViewports()
{
	if (SelectedObjectModifiedThisFrame && MyDetailLayout != nullptr)
	{
		// If there is any user interaction going on, we don't want to refresh the details panel.
		// (This would interupt the interaction and make sliders unusable)
		for (TWeakObjectPtr<UObject> UObjectPtr : ObjectsBeingCustomized)
		{
			if (UAkSurfaceReflectorSetComponent* reflectorSet = Cast<UAkSurfaceReflectorSetComponent>(UObjectPtr.Get()))
			{
				if (reflectorSet->UserInteractionInProgress)
				{
					return;
				}
			}
		}

		MyDetailLayout->ForceRefreshDetails();
		SelectedObjectModifiedThisFrame = false;
	}
}

TSharedRef<IDetailCustomization> FAkSurfaceReflectorSetDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FAkSurfaceReflectorSetDetailsCustomization());
}

void FAkSurfaceReflectorSetDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	DetailLayout.EditCategory("Toggle", FText::GetEmpty(), ECategoryPriority::Important);
	DetailLayout.EditCategory("Geometry Settings", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	DetailLayout.EditCategory("Fit To Geometry", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	MyDetailLayout = &DetailLayout;

	DetailLayout.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	auto AcousticPolysPropHandle = DetailLayout.GetProperty("AcousticPolys");
	DetailLayout.HideProperty("AcousticPolys");
	
	bool showGeometrySettings = false;
	for (int i = 0; i < ObjectsBeingCustomized.Num(); ++i)
	{
		ReflectorSetBeingCustomized = Cast<UAkSurfaceReflectorSetComponent>(ObjectsBeingCustomized[i].Get());
		if (ReflectorSetBeingCustomized && ReflectorSetBeingCustomized->bEnableSurfaceReflectors)
		{
			showGeometrySettings = true;
			break;
		}
	}

	if (!showGeometrySettings)
		DetailLayout.HideCategory("Geometry Settings");

	IDetailCategoryBuilder& CategoryBuilder = DetailLayout.EditCategory("Geometry Surfaces", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	FString enableEditSurfacesTooltip(FString("Enable ") + GEOMETRY_EDIT_DISPLAY_NAME + " and show only selected actors");
	FString disableEditSurfacesTooltip(FString("Disable ") + GEOMETRY_EDIT_DISPLAY_NAME + " and show all actors");

	CategoryBuilder.HeaderContent
	(
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.AutoWidth()
		[
			SAssignNew(SelectionInfoLabel, STextBlock)
			// SelectionInfoLabel is passed in to a SAcousticSurfacesController below, and the selection text is set during its construction.
			.Text(FText::FromString(""))
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Text(FText::FromString("Enable Edit Surfaces "))
			.ToolTipText(FText::FromString(enableEditSurfacesTooltip))
			.OnClicked(this, &FAkSurfaceReflectorSetDetailsCustomization::OnEnableEditModeClicked)
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Text(FText::FromString("Disable Edit Surfaces"))
			.ToolTipText(FText::FromString(disableEditSurfacesTooltip))
			.OnClicked(this, &FAkSurfaceReflectorSetDetailsCustomization::OnDisableEditModeClicked)
		]
	);
	// Assume Transmission Loss controls will be hidden
	int surfacePropertiesControlsHeight = 48;
	for (TWeakObjectPtr<UObject> ObjectBeingCustomized : ObjectsBeingCustomized)
	{
		UAkSurfaceReflectorSetComponent* reflectorSetComponent = Cast<UAkSurfaceReflectorSetComponent>(ObjectBeingCustomized.Get());
		if (reflectorSetComponent && reflectorSetComponent->bEnableSurfaceReflectors)
		{
			// There is a surface reflector set with bEnableSurfaceReflectors enabled - add room for Transmission Loss controls.
			surfacePropertiesControlsHeight = 72;
			break;
		}
	}
	FDetailWidgetRow& acousticSurfacesRow = CategoryBuilder.AddCustomRow(AcousticPolysPropHandle->GetPropertyDisplayName());
	acousticSurfacesRow.NameContent()
	[
		SNew(SBox)
		.HeightOverride(surfacePropertiesControlsHeight)
		[
			SNew(SAcousticSurfacesLabels, ObjectsBeingCustomized)
		]
	];
	acousticSurfacesRow.ValueContent()
	[
		SNew(SBox)
		.HeightOverride(surfacePropertiesControlsHeight)
		[
			SNew(SAcousticSurfacesController, ObjectsBeingCustomized, MyDetailLayout)
		]
	];

	if (ObjectsBeingCustomized.Num() == 1)
	{
		ReflectorSetBeingCustomized = Cast<UAkSurfaceReflectorSetComponent>(ObjectsBeingCustomized[0].Get());
		if (ReflectorSetBeingCustomized)
		{
			SetupGeometryModificationHandlers();
		}
	}
}

#define REGISTER_PROPERTY_CHANGED(Class, Property) \
	auto Property ## Handle = MyDetailLayout->GetProperty(GET_MEMBER_NAME_CHECKED(Class, Property), Class::StaticClass(), BrushBuilderName); \
	if (Property ## Handle->IsValidHandle()) Property ## Handle->SetOnPropertyValueChanged(FSimpleDelegate::CreateSP(this, &FAkSurfaceReflectorSetDetailsCustomization::OnGeometryChanged))

void FAkSurfaceReflectorSetDetailsCustomization::SetupGeometryModificationHandlers()
{
	static const FName BrushBuilderName(TEXT("BrushBuilder"));
	auto ParentBrush = ReflectorSetBeingCustomized->ParentBrush;
	if(!ParentBrush)
		return;

	auto EnableHandle = MyDetailLayout->GetProperty("bEnableSurfaceReflectors");
	EnableHandle->SetOnPropertyValueChanged(FSimpleDelegate::CreateSP(this, &FAkSurfaceReflectorSetDetailsCustomization::OnEnableValueChanged));

	// This is to detect if the BrushBuilder changed.
	if (ReflectorSetBeingCustomized->AcousticPolys.Num() != ParentBrush->Nodes.Num())
		MyDetailLayout->GetPropertyUtilities()->EnqueueDeferredAction(FSimpleDelegate::CreateSP(this, &FAkSurfaceReflectorSetDetailsCustomization::OnGeometryChanged));
		
	// Need to register to a LOT of different properties, because some change the geometry but don't force a refresh of the details panel
	AVolume* ParentVolume = Cast<AVolume>(ReflectorSetBeingCustomized->GetOwner());
	UClass* BrushBuilderClass = nullptr;
	if (ParentVolume && ParentVolume->BrushBuilder)
	{
		BrushBuilderClass = ParentVolume->BrushBuilder->GetClass();
		if (BrushBuilderClass == nullptr)
		{
			return;
		}
	}

	if (BrushBuilderClass == UConeBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(UConeBuilder, Sides);
		REGISTER_PROPERTY_CHANGED(UConeBuilder, Hollow);
	}
	else if (BrushBuilderClass == UCubeBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(UCubeBuilder, Hollow);
		REGISTER_PROPERTY_CHANGED(UCubeBuilder, Tessellated);
	}
	else if (BrushBuilderClass == UCurvedStairBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(UCurvedStairBuilder, NumSteps);
	}
	else if (BrushBuilderClass == UCylinderBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(UCylinderBuilder, Sides);
		REGISTER_PROPERTY_CHANGED(UCylinderBuilder, Hollow);
	}
	else if (BrushBuilderClass == ULinearStairBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(ULinearStairBuilder, NumSteps);
	}
	else if (BrushBuilderClass == USpiralStairBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(USpiralStairBuilder, NumSteps);
	}
	else if (BrushBuilderClass == UTetrahedronBuilder::StaticClass())
	{
		REGISTER_PROPERTY_CHANGED(UTetrahedronBuilder, SphereExtrapolation);
	}

	FOnRefreshDetails DetailsChanged = FOnRefreshDetails::CreateRaw(this, &FAkSurfaceReflectorSetDetailsCustomization::OnEnableValueChanged);
	ReflectorSetBeingCustomized->SetOnRefreshDetails(DetailsChanged);
}

void FAkSurfaceReflectorSetDetailsCustomization::OnEnableValueChanged()
{
	ReflectorSetBeingCustomized->ClearOnRefreshDetails();
	MyDetailLayout->ForceRefreshDetails();
}

void FAkSurfaceReflectorSetDetailsCustomization::OnGeometryChanged()
{
	ReflectorSetBeingCustomized->UpdatePolys();
	ReflectorSetBeingCustomized->ClearOnRefreshDetails();
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE