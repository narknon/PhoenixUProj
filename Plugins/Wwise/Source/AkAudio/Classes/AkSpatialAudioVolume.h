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
	AkReverbVolume.h:
=============================================================================*/
#pragma once

#include "GameFramework/Volume.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "AkLateReverbComponent.h"
#include "AkRoomComponent.h"
#include "AkSpatialAudioVolume.generated.h"

UENUM()
enum class EAkFitToGeometryMode : uint32
{
	/**
	Oriented Box: The Ak Spatial Audio Volume is fit to the surrounding geometry using a minimum volume oriented bounding box. 
	Use for shoe box shaped rooms with and arbitrary extent and rotation.
	*/
	OrientedBox,
	
	/**
	Aligned Box: The Ak Spatial Audio Volume is fit to the surrounding geometry using an aligned bounding box, aligned to the local axes of the Actor. 
	Use for shoe box shaped rooms with an arbitrary extent, but with the rotation supplied by the user.
	The actor is rotated manually in the editor to achieve desired alignment.
	*/
	AlignedBox,
	
	/**
	Convex Polyhedron: The Ak Spatial Audio Volume is fit to the surrounding geometry using a convex polyhedron. Use for arbitrary-shaped convex rooms. 
	Will likely result in a more complex (higher poly-count) shape, and will possibly resulting in greater CPU and memory usage than oriented or aligned box shapes.
	When using convex polyhedron, a room must be fully enclosed; open ceilings or walls are not permitted and will cause a failure to fit to geometry.
	*/
	ConvexPolyhedron
};

/*------------------------------------------------------------------------------------
	AAkSpatialAudioVolume
------------------------------------------------------------------------------------*/
UCLASS(ClassGroup = Audiokinetic, BlueprintType, hidecategories = (Advanced, Attachment, Volume))
class AKAUDIO_API AAkSpatialAudioVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
	void FitRaycast();
	void FitBox(bool bPreviewOnly = false);
	bool bBrushNeedsRebuild = false;
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void PostTransacted(const FTransactionObjectEvent& TransactionEvent) override;
	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	const TArray<FVector>& GetRaycastHits() const { return FitPoints; }
	float GetFitScale() const { return FilterHitPoints; }
	static const int kNumRaycasts = 32;

	virtual FName GetCustomIconName() const override
	{
		static const FName IconName("ClassIcon.AkSpatialAudioVolume");
		return IconName;
	}

	void PostRebuildBrush();
	void ClearTextComponents();
	void UpdatePreviewTextComponents(TArray<FVector> positions);
	void UpdatePreviewPolys(TArray<TMap<TWeakObjectPtr<UPhysicalMaterial>, int>> materialVotes);
	TArray<FAkSurfacePoly> PreviewPolys;
#endif

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SurfaceReflectorSet", meta = (ShowOnlyInnerProperties))
	UAkSurfaceReflectorSetComponent* SurfaceReflectorSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LateReverb", meta = (ShowOnlyInnerProperties))
	UAkLateReverbComponent* LateReverb;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Room", meta = (ShowOnlyInnerProperties))
	UAkRoomComponent* Room;

#if WITH_EDITORONLY_DATA

	/**
	Automatically fit the Ak Spatial Audio Volume to the surrounding geometry. The fitting operation is performed after enabling this property, or after moving the actor to a new location.
	The fitting operation is performed by casting rays emanating spherically outwards from the origin of the actor. 
	The points where the rays hit the surrounding geometry (drawn in the editor as green dots) are fit to a shape (box or convex polyhedron), and the actor is then resized appropriately.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry" )
	bool FitToGeometry = false;

	/**
	Set the collision channel for the ray traces performed to fit the portal to the surrounding geometry. The default value for the collision channel is specified in the Wwise integration settings.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	/** 
	Choose the shape with which to fit to the surrounding geometry. 
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry" )
	EAkFitToGeometryMode Shape = EAkFitToGeometryMode::AlignedBox;

	/**
	Set to a value less then 1.0 to filter out a percentage of the ray cast hits for use in fitting to surrounding geometry. 
	Points that have been rejected by the filter are drawn in red, and points accepted drawn in green. 
	Particularly useful when rays happen to escape through windows or other openings, resulting in undesirable points.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry", meta = (ClampMin = 0.1875f, ClampMax = 1.0f))
	float FilterHitPoints = 1.0f;

	UPROPERTY()
	TArray<FVector> FitPoints;
	
	UPROPERTY()
	TArray<FVector> FitNormals;

	UPROPERTY()
	TArray< TWeakObjectPtr<class UPhysicalMaterial> > FitMaterials;
	
	UPROPERTY()
	FRotator SavedRotation;

	TArray< TPair< FVector, FVector> > PreviewOutline;
	bool IsDragging = false;

	UPROPERTY()
	bool FitFailed = false;

	// Used by the visualizer when scaling the preview text components.
	float LongestEdgeLength = 0.0f;
	mutable TArray<UTextRenderComponent*> PreviewTextureNameComponents;

private:
	FBoxSphereBounds PreviousBounds = FBoxSphereBounds();
#endif
};
