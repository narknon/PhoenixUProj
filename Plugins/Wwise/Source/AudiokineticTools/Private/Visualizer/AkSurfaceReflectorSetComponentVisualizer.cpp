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


/*=============================================================================
AkWwiseAcousticsComponentVisualizer.cpp:
=============================================================================*/
#include "AkSurfaceReflectorSetComponentVisualizer.h"
#include "AkAudioDevice.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "AkSpatialAudioVolume.h"
#include "Editor.h"
#include "EditorModeManager.h"
#include "EditorModes.h"
#include "Components/BrushComponent.h"
#include "Components/TextRenderComponent.h"
#include "Model.h"
#include "Engine/Polys.h"
#include "EngineGlobals.h"
#include "DynamicMeshBuilder.h"
#include "Materials/Material.h"
#include "Editor.h"
#include "LevelEditorViewport.h"
#include "AkSpatialAudioDrawUtils.h"
#include "Components/BrushComponent.h"
#include "Engine/Canvas.h"

#include <cmath>

#define AK_VISUALIZE_HIT_MATERIALS 0

void FAkSurfaceReflectorSetComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	if (Component == nullptr)
	{
		return;
	}

	const UAkSurfaceReflectorSetComponent* SurfaceReflectorSet = Cast<const UAkSurfaceReflectorSetComponent>(Component);
	const AAkSpatialAudioVolume* SpatialAudioVolume = Cast<const AAkSpatialAudioVolume>(Component->GetOwner());

	if (SpatialAudioVolume == nullptr)
		return;

	auto ModelBrush = SurfaceReflectorSet->ParentBrush;
	if (SurfaceReflectorSet != nullptr &&
		ModelBrush != nullptr &&
		!SpatialAudioVolume->IsHiddenEd())
	{
		// Build a mesh by basically drawing the triangles of each 
		for (int32 NodeIdx = 0; 
			NodeIdx < ModelBrush->Nodes.Num() && NodeIdx < SurfaceReflectorSet->TextVisualizers.Num();
			++NodeIdx)
		{
			FDynamicMeshBuilder MeshBuilder(ERHIFeatureLevel::Type::ES3_1);
			int32 VertStartIndex = SurfaceReflectorSet->ParentBrush->Nodes[NodeIdx].iVertPool;

			FUnrealFloatVector normal(ModelBrush->Nodes[NodeIdx].Plane);
			if (SurfaceReflectorSet->AcousticPolys.Num() > NodeIdx)
			{
				if (SurfaceReflectorSet->AcousticPolys[NodeIdx].EnableSurface &&
					ModelBrush->Nodes[NodeIdx].NumVertices > 2)
				{
					// Shift the vertices in towards the center (negatively along the normal) so that they don't obstruct face selection in geometry mode / brush editing mode.
					FUnrealFloatVector offset = normal * 0.1f;

					const FVert& Vert0 = ModelBrush->Verts[VertStartIndex + 0];
					const FVert& Vert1 = ModelBrush->Verts[VertStartIndex + 1];
					const FVert& Vert2 = ModelBrush->Verts[VertStartIndex + 2];
					FUnrealFloatVector Vertex0 = ModelBrush->Points[Vert0.pVertex] - offset;
					FUnrealFloatVector Vertex1 = ModelBrush->Points[Vert1.pVertex] - offset;
					FUnrealFloatVector Vertex2 = ModelBrush->Points[Vert2.pVertex] - offset;

					MeshBuilder.AddVertex(Vertex0, FUnrealFloatVector2D::ZeroVector, FUnrealFloatVector(1, 0, 0), FUnrealFloatVector(0, 1, 0), FUnrealFloatVector(0, 0, 1), FColor::White);
					MeshBuilder.AddVertex(Vertex1, FUnrealFloatVector2D::ZeroVector, FUnrealFloatVector(1, 0, 0), FUnrealFloatVector(0, 1, 0), FUnrealFloatVector(0, 0, 1), FColor::White);
					MeshBuilder.AddVertex(Vertex2, FUnrealFloatVector2D::ZeroVector, FUnrealFloatVector(1, 0, 0), FUnrealFloatVector(0, 1, 0), FUnrealFloatVector(0, 0, 1), FColor::White);
					MeshBuilder.AddTriangle(0, 2, 1);
					MeshBuilder.AddTriangle(1, 2, 0);

					for (int32 VertexIdx = 3; VertexIdx < ModelBrush->Nodes[NodeIdx].NumVertices; ++VertexIdx)
					{
						const FVert& Vert3 = ModelBrush->Verts[VertStartIndex + VertexIdx];
						FUnrealFloatVector Vertex3 = ModelBrush->Points[Vert3.pVertex] - offset;

						MeshBuilder.AddVertex(Vertex3, FUnrealFloatVector2D::ZeroVector, FUnrealFloatVector(1, 0, 0), FUnrealFloatVector(0, 1, 0), FUnrealFloatVector(0, 0, 1), FColor::White);
						MeshBuilder.AddTriangle(0, VertexIdx, VertexIdx - 1);
						MeshBuilder.AddTriangle(VertexIdx - 1, VertexIdx, 0);
					}

					FLinearColor SurfaceColor = AkSpatialAudioColors::GetSurfaceReflectorColor(SurfaceReflectorSet, NodeIdx, SpatialAudioVolume->IsDragging);
#if UE_4_22_OR_LATER
					auto* renderProxy = GEngine->GeomMaterial->GetRenderProxy();
#else
					auto* renderProxy = GEngine->GeomMaterial->GetRenderProxy(false);
#endif
					// Limit the color's value (in HSV space) so that it doesn't obscure the text.
					// In the new color, R = H, G = S, B = V, A = A (From Color.cpp line ~271)
					FLinearColor hsv = SurfaceColor.LinearRGBToHSV();
					hsv.B = FMath::Min(0.25f, hsv.B);
					SurfaceColor = hsv.HSVToLinearRGB();
					FDynamicColoredMaterialRenderProxy* MatProxy = new FDynamicColoredMaterialRenderProxy(renderProxy, SurfaceColor);
					PDI->RegisterDynamicResource(MatProxy);
					MeshBuilder.Draw(PDI, SpatialAudioVolume->ActorToWorld().ToMatrixWithScale(), MatProxy, SDPG_World, true);
				}
			}
		}

		SurfaceReflectorSet->UpdateTextPositions();

		if (!GLevelEditorModeTools().IsModeActive(FEditorModeID(TEXT("EM_Geometry"))))
		{
			for (auto& KV : SurfaceReflectorSet->EdgeMap)
			{
				auto& EdgeInfo = KV.Value;

				if (!EdgeInfo.IsFlat && (!EdgeInfo.IsBoundary || SurfaceReflectorSet->bEnableDiffractionOnBoundaryEdges))
				{
					FLinearColor EdgeColor = AkSpatialAudioColors::GetSpatialAudioVolumeOutlineColor();
					float Thickness = SurfaceReflectorSet->bEnableSurfaceReflectors ? AkDrawConstants::SpatialAudioVolumeOutlineThickness : AkDrawConstants::RoomOutlineThickness;
					if (EdgeInfo.IsEnabled &&
						SurfaceReflectorSet->bEnableSurfaceReflectors &&
						SurfaceReflectorSet->bEnableDiffraction)
					{
						EdgeColor = EdgeInfo.IsBoundary ? AkSpatialAudioColors::GetBoundaryDiffractionEdgeColor() : AkSpatialAudioColors::GetDiffractionEdgeColor();
						Thickness = AkDrawConstants::DiffractionEdgeThickness;
					}
					PDI->DrawLine(EdgeInfo.V0(), EdgeInfo.V1(), EdgeColor, SDPG_World, Thickness);
				}
			}
		}
	}

	if (GEditor->GetSelectedActorCount() == 1 &&
		(!SpatialAudioVolume->IsHiddenEd() || SpatialAudioVolume->IsDragging) &&
		SpatialAudioVolume->FitToGeometry)
	{
		for (int i = 0; i < SpatialAudioVolume->GetRaycastHits().Num(); ++i)
		{
			int Threshold = (int)(SpatialAudioVolume->GetFitScale() * SpatialAudioVolume->GetRaycastHits().Num());
			FColor col = i <= Threshold ? FColor::Green : FColor::Red;
			PDI->DrawLine(SpatialAudioVolume->FitPoints[i], SpatialAudioVolume->FitPoints[i] + SpatialAudioVolume->FitNormals[i] * 10.f, col, 100);
			PDI->DrawPoint(SpatialAudioVolume->GetRaycastHits()[i], col, 5.f, 100);
		}

		if (SpatialAudioVolume->IsDragging)
		{
			for (auto& EdgePair : SpatialAudioVolume->PreviewOutline)
			{
				PDI->DrawLine(EdgePair.Key, EdgePair.Value, AkSpatialAudioColors::GetSpatialAudioVolumeOutlineColor() * 1.35f, SDPG_Foreground, 7.0f);
			}
		}

		if (SpatialAudioVolume->FitFailed &&
			!SpatialAudioVolume->IsDragging &&
			SpatialAudioVolume->GetBrushComponent())
		{
			static const float kFlashPeriodSeconds = 0.3f;
			static const float kFlashDutyCycle = 0.5f;
			static const float kFlashDurationSeconds = 0.6f;

			if (FlashTimer == FLT_MAX)
				FlashTimer = 0.f;

			if (fmod(FlashTimer, kFlashPeriodSeconds) < kFlashDutyCycle*kFlashPeriodSeconds &&
				FlashTimer < kFlashDurationSeconds)
			{
				UModel* Brush = SpatialAudioVolume->GetBrushComponent()->Brush;
				if (Brush)
				{
					for (int32 NodeIdx = 0; NodeIdx < Brush->Nodes.Num(); ++NodeIdx)
					{
						int32 VertStartIndex = Brush->Nodes[NodeIdx].iVertPool;
						int32 NumVerts = Brush->Nodes[NodeIdx].NumVertices;
						for (int32 j = NumVerts - 1, i = 0; i < NumVerts; j = i, ++i)
						{
							auto V0 = Brush->Points[Brush->Verts[VertStartIndex + i].pVertex];
							auto V1 = Brush->Points[Brush->Verts[VertStartIndex + j].pVertex];

							FVector WorldV0 = SpatialAudioVolume->GetActorTransform().TransformPosition(FVector(V0));
							FVector WorldV1 = SpatialAudioVolume->GetActorTransform().TransformPosition(FVector(V1));

							PDI->DrawLine(WorldV0, WorldV1, AkSpatialAudioColors::GetBadFitSpatialAudioVolumeOutlineColor(), SDPG_Foreground, 7.0f);
						}
					}
				}
			}

#if UE_5_0_OR_LATER
			FlashTimer += View->Family->Time.GetDeltaWorldTimeSeconds();
#else
			FlashTimer += View->Family->DeltaWorldTime;
#endif
		}
		else
		{
			FlashTimer = FLT_MAX;
		}
	}
}

void FAkSurfaceReflectorSetComponentVisualizer::DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	if (GLevelEditorModeTools().IsModeActive(FEditorModeID(TEXT("EM_Geometry"))) || Component == nullptr)
	{
		return;
	}

	const AAkSpatialAudioVolume* SpatialAudioVolume = Cast<const AAkSpatialAudioVolume>(Component->GetOwner());

	if (SpatialAudioVolume == nullptr)
		return;

	if (SpatialAudioVolume->FitToGeometry &&
		SpatialAudioVolume->FitFailed &&
		!SpatialAudioVolume->IsDragging)
	{
		static FText Text = FText::FromString("Fit to geometry failed. Try moving Spatial Audio Volume to a new location.");
		FCanvasTextItem TextItem(FVector2D::ZeroVector, Text, GEngine->GetSmallFont(), AkSpatialAudioColors::GetBadFitSpatialAudioVolumeOutlineColor());
		float YPos = (Canvas->GetViewRect().Height() / Canvas->GetDPIScale()) - GEngine->GetSmallFont()->GetMaxCharHeight();
		Canvas->DrawItem(TextItem, 0, YPos);
	}

#if AK_VISUALIZE_HIT_MATERIALS
	if (SpatialAudioVolume->FitToGeometry)
	{
		for (int i = 0; i < SpatialAudioVolume->GetRaycastHits().Num()*SpatialAudioVolume->GetFitScale(); ++i)
		{
			FVector Location = SpatialAudioVolume->GetRaycastHits()[i];
			FPlane Proj = View->Project(Location);
			if (Proj.W > 0.f)
			{
				float Height = Canvas->GetViewRect().Height() / Canvas->GetDPIScale();
				float Width = Canvas->GetViewRect().Width() / Canvas->GetDPIScale();
				float X = (Width / 2.f) + (Proj.X * (Width / 2.f));
				float Y = (Height / 2.f) + (-Proj.Y * (Height / 2.f));

				FCanvasTextItem TextItem(FVector2D::ZeroVector, FText::FromString(SpatialAudioVolume->FitMaterials[i]->GetName()), GEngine->GetTinyFont(), FColor::Green);
				Canvas->DrawItem(TextItem, X, Y);
			}
		}
	}
#endif
}
