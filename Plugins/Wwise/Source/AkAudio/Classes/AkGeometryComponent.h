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

#pragma once
#include "Platforms/AkUEPlatform.h"
#include "AkAcousticTexture.h"
#include "Components/SceneComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "AkAcousticTextureSetComponent.h"
#include "AkGeometryData.h"
#include "AkGeometryComponent.generated.h"

class UAkSettings;
#if UE_5_0_OR_LATER
class UMaterialInterface;
#endif

DECLARE_DELEGATE(FOnRefreshDetails);

UENUM()
enum class AkMeshType : uint8
{
	StaticMesh,
	CollisionMesh UMETA(DisplayName = "Simple Collision")
};

USTRUCT(BlueprintType)
struct FAkGeometrySurfaceOverride
{
	GENERATED_USTRUCT_BODY()

	/** The Acoustic Texture represents the sound absorption on the surface of the geometry when a sound bounces off of it.
	* If left to None, the mesh's physical material will be used to fetch an acoustic texture.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry")
	UAkAcousticTexture* AcousticTexture = nullptr;

	/** Enable Transmission Loss Override */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Enable Transmission Loss Override", Category = "Geometry")
	uint32 bEnableOcclusionOverride : 1;

	/** Transmission loss value to set when modeling sound transmission through geometry. Transmission is modeled only when there is no direct line of sight from the emitter to the listener.
	* If there is more than one surface between the emitter and the listener, the maximum of each surface's transmission loss value is used. If the emitter and listener are in different rooms, the room's transmission loss value is taken into account.
	* Valid range : (0.0, 1.0)
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", DisplayName = "Transmission Loss", meta = (EditCondition = "bEnableOcclusionOverride", ClampMin = "0.0", ClampMax = "1.0"))
	float OcclusionValue = 1.f;

	void SetSurfaceArea(float area) { SurfaceArea = area; }

	FAkGeometrySurfaceOverride()
	{
		AcousticTexture = nullptr;
		bEnableOcclusionOverride = false;
		OcclusionValue = 1.f;
	}

private:
	UPROPERTY()
	float SurfaceArea = 0.0f;

};

UCLASS(ClassGroup = Audiokinetic, BlueprintType, hidecategories = (Transform, Rendering, Mobility, LOD, Component, Activation, Tags), meta = (BlueprintSpawnableComponent))
class AKAUDIO_API UAkGeometryComponent : public UAkAcousticTextureSetComponent
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkGeometry")
	void ConvertMesh();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkGeometry")
	void RemoveGeometry();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkGeometry")
	void UpdateGeometry();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkGeometry")
	void SendGeometry();

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Geometry")
	AkMeshType MeshType;

	/** The Static Mesh's LOD to use */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", meta = (ClampMin = "0.0"))
	int LOD;

	/** The local distance in Unreal units between two vertices to be welded together.
	* Any two vertices closer than this threshold will be treated as the same unique vertex and assigned the same position.
	* Increasing this threshold decreases the number of gaps between triangles, resulting in a more continuous mesh and less sound leaking though, as well as eliminating triangles that are too small to be significant.
	* Increasing this threshold also helps Spatial Audio's edge-finding algorithm to find more valid diffraction edges.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", meta = (ClampMin = "0.0"))
	float WeldingThreshold;

	/** Override the acoustic properties of this mesh per material.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", DisplayName = "Acoustic Properties Override")
	TMap<UMaterialInterface*, FAkGeometrySurfaceOverride> StaticMeshSurfaceOverride;

	/** Override the acoustic properties of the collision mesh.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", DisplayName = "Acoustic Properties Override")
	FAkGeometrySurfaceOverride CollisionMeshSurfaceOverride;

	/** Enable or disable geometric diffraction for this mesh. Check this box to have Wwise Spatial Audio generate diffraction edges on the geometry. The diffraction edges will be visible in the Wwise game object viewer when connected to the game. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry")
	uint32 bEnableDiffraction : 1;

	/** Enable or disable geometric diffraction on boundary edges for this Geometry. Boundary edges are edges that are connected to only one triangle. Depending on the specific shape of the geometry, boundary edges may or may not be useful and it is beneficial to reduce the total number of diffraction edges to process.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry", meta = (EditCondition = "bEnableDiffraction"))
	uint32 bEnableDiffractionOnBoundaryEdges : 1;

	/** (Optional) Associate this Surface Reflector Set with a Room.
	* Associating a spatial audio geometry with a particular room will limit the scope in which the geometry is visible/accessible. Leave it to None and this geometry will have a global scope.
	* It is recommended to associate geometry with a room when the geometry is (1) fully contained within the room (ie. not visible to other rooms except by portals), and (2) the room does not share geometry with other rooms. Doing so reduces the search space for ray casting performed by reflection and diffraction calculations.
	* Take note that once one or more geometry sets are associated with a room, that room will no longer be able to access geometry that is in the global scope.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry")
	AActor* AssociatedRoom;

	float GetSurfaceAreaSquaredMeters(const int& surfaceIndex) const;

	void UpdateStaticMeshOverride();

#if WITH_EDITORONLY_DATA
	void SetOnRefreshDetails(const FOnRefreshDetails& in_delegate) { OnRefreshDetails = in_delegate; }
	void ClearOnRefreshDetails() { OnRefreshDetails.Unbind(); }
	const FOnRefreshDetails* GetOnRefreshDetails() { return &OnRefreshDetails; }

	bool bMeshMaterialChanged = false;
#endif

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditUndo() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
#endif

	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) override;
	virtual bool MoveComponentImpl(
		const FVector & Delta,
		const FQuat & NewRotation,
		bool bSweep,
		FHitResult * Hit,
		EMoveComponentFlags MoveFlags,
		ETeleportType Teleport) override;
	virtual void Serialize(FArchive& Ar) override;

	void GetTexturesAndSurfaceAreas(TArray<FAkAcousticTextureParams>& textures, TArray<float>& surfaceAreas) const override;

	/** Indicates whether this component was added dynamically by a sibling room component in order to send geometry to Wwise. */
	bool bWasAddedByRoom = false;

private:

	UPrimitiveComponent* Parent = nullptr;
	void InitializeParent();

	void CalculateSurfaceArea(UStaticMeshComponent* StaticMeshComponent);

	void ConvertStaticMesh(UStaticMeshComponent* StaticMeshComponent, const UAkSettings* AkSettings);
	void ConvertCollisionMesh(UPrimitiveComponent* PrimitiveComponent, const UAkSettings* AkSettings);
	void UpdateMeshAndArchetype(UStaticMeshComponent* StaticMeshComponent);
	void _UpdateStaticMeshOverride(UStaticMeshComponent* StaticMeshComponent);
	void UpdateGeometryTransform();

	UPROPERTY()
	FAkGeometryData GeometryData;

	UPROPERTY()
	TMap<int, double> SurfaceAreas;
	
	TMap<UMaterialInterface*, FAkGeometrySurfaceOverride> PreviousStaticMeshSurfaceOverride;

	void BeginPlayInternal();
#if WITH_EDITOR
	virtual void HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap) override;
	bool bRequiresDeferredBeginPlay = false;
	void RegisterAllTextureParamCallbacks() override;
	bool ContainsTexture(const FGuid& textureID) override;
#endif

#if WITH_EDITORONLY_DATA
	FOnRefreshDetails OnRefreshDetails;
	FDelegateHandle OnMeshMaterialChangedHandle;
#endif
};
