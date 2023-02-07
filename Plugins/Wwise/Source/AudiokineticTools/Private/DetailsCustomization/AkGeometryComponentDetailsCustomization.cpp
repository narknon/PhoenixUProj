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

#include "AkGeometryComponentDetailsCustomization.h"
#include "AkGeometryComponent.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Editor/TransBuffer.h"
#include "PropertyCustomizationHelpers.h"
#include "UI/SAkGeometrySurfaceOverrideController.h"
#include "Widgets/Input/SButton.h"

#define LOCTEXT_NAMESPACE "AudiokineticTools"

static int SurfacePropertiesHeight = 72;

//////////////////////////////////////////////////////////////////////////
// FAkGeometryDetailsCustomization

FAkGeometryComponentDetailsCustomization::FAkGeometryComponentDetailsCustomization()
{
	ComponentBeingCustomized = nullptr;
}

FAkGeometryComponentDetailsCustomization::~FAkGeometryComponentDetailsCustomization()
{
	if (ComponentBeingCustomized && ComponentBeingCustomized->IsValidLowLevelFast() && ComponentBeingCustomized->GetOnRefreshDetails())
	{
		if (ComponentBeingCustomized->GetOnRefreshDetails()->IsBoundToObject(this))
		{
			ComponentBeingCustomized->ClearOnRefreshDetails();
		}
		ComponentBeingCustomized = nullptr;
	}
}

void FAkGeometryComponentDetailsCustomization::BeginModify(FText TransactionText)
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

void FAkGeometryComponentDetailsCustomization::EndModify()
{
	if (GEditor && GEditor->Trans)
	{
		UTransBuffer* TransBuffer = CastChecked<UTransBuffer>(GEditor->Trans);
		if (TransBuffer != nullptr)
			TransBuffer->End();
	}
}

TSharedRef<IDetailCustomization> FAkGeometryComponentDetailsCustomization::MakeInstance()
{
	return MakeShared<FAkGeometryComponentDetailsCustomization>();
}

void FAkGeometryComponentDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	MyDetailLayout = &DetailLayout;
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailLayout.GetObjectsBeingCustomized(ObjectsBeingCustomized);

	DetailLayout.EditCategory("Geometry", FText::GetEmpty(), ECategoryPriority::TypeSpecific);

	for (TWeakObjectPtr<UObject>& Object : ObjectsBeingCustomized)
	{
		UAkGeometryComponent* GeometryComponentBeingCustomized = Cast<UAkGeometryComponent>(Object.Get());
		if (GeometryComponentBeingCustomized)
		{
			UObject* OuterObj = GeometryComponentBeingCustomized->GetOuter();
			UActorComponent* OuterComponent = Cast<UActorComponent>(OuterObj);
			AActor* OuterActor = Cast<AActor>(OuterObj);
			// Do not hide the transform if the component has been created from within a component or actor, as this will hide the transform for that component / actor as well
			// (i.e. - only hide the transform if the component has been added to the hierarchy of a blueprint class or actor instance from the editor)
			if (OuterComponent == nullptr && OuterActor == nullptr)
			{
				IDetailCategoryBuilder& TransformCategory = DetailLayout.EditCategory("TransformCommon", LOCTEXT("TransformCommonCategory", "Transform"), ECategoryPriority::Transform);
				TransformCategory.SetCategoryVisibility(false);
				break;
			}
		}
	}

	if (ObjectsBeingCustomized.Num() != 1)
	{
		return;
	}

	ComponentBeingCustomized = Cast<UAkGeometryComponent>(ObjectsBeingCustomized[0].Get());
	if (ComponentBeingCustomized)
	{
		auto meshTypeChangedHandle = MyDetailLayout->GetProperty("MeshType");
		meshTypeChangedHandle->SetOnPropertyValueChanged(FSimpleDelegate::CreateSP(this, &FAkGeometryComponentDetailsCustomization::RefreshDetails));

		FOnRefreshDetails refreshDetails = FOnRefreshDetails::CreateSP(this, &FAkGeometryComponentDetailsCustomization::RefreshDetails);
		ComponentBeingCustomized->SetOnRefreshDetails(refreshDetails);

		if (ComponentBeingCustomized->MeshType == AkMeshType::StaticMesh)
		{
			DetailLayout.HideProperty("CollisionMeshSurfaceOverride");
			if (ObjectsBeingCustomized.Num() == 1)
			{
				IDetailCategoryBuilder& CategoryBuilder = DetailLayout.EditCategory("Surface Overrides", FText::GetEmpty(), ECategoryPriority::TypeSpecific);

				DetailLayout.HideProperty("StaticMeshSurfaceOverride");
				auto SurfacesPropHandle = DetailLayout.GetProperty("StaticMeshSurfaceOverride");
				CategoryBuilder.HeaderContent
				(
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					[
						SNew(SButton)
						.Text(FText::FromString("Reset to Defaults"))
						.ToolTipText(FText::FromString(FString("Reset the surface properties to their default values.")))
						.OnClicked_Lambda([this, SurfacesPropHandle]()
							{
								BeginModify(FText::FromString(FString("Reset surface properties to defaults")));
								if (ComponentBeingCustomized->HasAnyFlags(RF_ArchetypeObject)
									|| ComponentBeingCustomized->CreationMethod == EComponentCreationMethod::Instance)
								{
									TArray<UMaterialInterface*> Materials;
									ComponentBeingCustomized->StaticMeshSurfaceOverride.GetKeys(Materials);
									for (UMaterialInterface* Material : Materials)
									{
										ComponentBeingCustomized->StaticMeshSurfaceOverride[Material].AcousticTexture = nullptr;
										ComponentBeingCustomized->StaticMeshSurfaceOverride[Material].bEnableOcclusionOverride = false;
										ComponentBeingCustomized->StaticMeshSurfaceOverride[Material].OcclusionValue = 1.0f;
									}
								}
								else
								{
									ComponentBeingCustomized->StaticMeshSurfaceOverride.Empty();
									SurfacesPropHandle->ResetToDefault();
								}
								EndModify();
								return FReply::Handled();
							})
					]
				);
				ComponentBeingCustomized->UpdateStaticMeshOverride();
				TArray<UMaterialInterface*> Materials;
				ComponentBeingCustomized->StaticMeshSurfaceOverride.GetKeys(Materials);
				for (UMaterialInterface* Material : Materials)
				{
					FDetailWidgetRow& SurfacesRow = CategoryBuilder.AddCustomRow(FText::FromString("Texture Surface Occlusion"));
					SurfacesRow.NameContent()
					[
						SNew(SBox)
						.HeightOverride(SurfacePropertiesHeight)
						.ToolTipText(FText::FromString("The material(s) in this list are populated using the materials assigned to the AkGeometry Component's Static Mesh parent Component."))
						[
							SNew(SObjectPropertyEntryBox)
							.AllowedClass(UMaterialInterface::StaticClass())
							.ObjectPath_Lambda([Material]() { return FSoftObjectPath(Material).GetAssetPathString(); })
							.ToolTipText(FText::FromString("The material(s) in this list are populated using the materials assigned to the AkGeometry Component's Static Mesh parent Component."))
							.IsEnabled(false)
						]
					];
					SurfacesRow.ValueContent()
					[
						SNew(SBox)
						.HeightOverride(SurfacePropertiesHeight)
						[
							SNew(SAkGeometryStaticMeshSurfaceController, ObjectsBeingCustomized[0], MyDetailLayout, Material)
						]
					];
				}
			}
		}
		else if (ComponentBeingCustomized->MeshType == AkMeshType::CollisionMesh)
		{
			DetailLayout.HideProperty("LOD");
			DetailLayout.HideProperty("WeldingThreshold");
			DetailLayout.HideProperty("StaticMeshSurfaceOverride");

			if (ObjectsBeingCustomized.Num() == 1)
			{
				IDetailCategoryBuilder& CategoryBuilder = DetailLayout.EditCategory("Surface Overrides", FText::GetEmpty(), ECategoryPriority::TypeSpecific);

				auto SurfacesPropHandle = DetailLayout.GetProperty("CollisionMeshSurfaceOverride");
				DetailLayout.HideProperty("CollisionMeshSurfaceOverride");

				CategoryBuilder.HeaderContent
				(
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					[
						SNew(SButton)
						.Text(FText::FromString("Reset to Defaults"))
						.ToolTipText(FText::FromString(FString("Reset the surface properties to their default values.")))
						.OnClicked_Lambda([this, SurfacesPropHandle]() 
						{
							BeginModify(FText::FromString(FString("Reset surface properties to defaults")));
							if (ComponentBeingCustomized->HasAnyFlags(RF_ArchetypeObject)
								|| ComponentBeingCustomized->CreationMethod == EComponentCreationMethod::Instance)
							{
								ComponentBeingCustomized->CollisionMeshSurfaceOverride.AcousticTexture = nullptr;
								ComponentBeingCustomized->CollisionMeshSurfaceOverride.bEnableOcclusionOverride = false;
								ComponentBeingCustomized->CollisionMeshSurfaceOverride.OcclusionValue = 1.0f;
							}
							else
							{
								SurfacesPropHandle->ResetToDefault();
							}
							EndModify();
							return FReply::Handled();
						})
					]
				);

				FDetailWidgetRow& SurfacesRow = CategoryBuilder.AddCustomRow(FText::FromString("Texture Surface Occlusion"));

				SurfacesRow.ValueContent()
				[
					SNew(SBox)
					.HeightOverride(SurfacePropertiesHeight)
					[
						SNew(SAkGeometryCollisionMeshSurfaceController, ObjectsBeingCustomized[0], MyDetailLayout)
					]
				];
			}
		}
	}
}

void FAkGeometryComponentDetailsCustomization::RefreshDetails()
{
	if (ComponentBeingCustomized)
		ComponentBeingCustomized->ClearOnRefreshDetails();

	if (MyDetailLayout)
		MyDetailLayout->ForceRefreshDetails();
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE