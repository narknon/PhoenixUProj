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

#include "GameFramework/Volume.h"
#include "OcclusionObstructionService/AkPortalOcclusionObstructionService.h"
#include "AkGameplayTypes.h"

#include "AkAcousticPortal.generated.h"

class UAkRoomComponent;
class UAkLateReverbComponent;

UCLASS(ClassGroup = Audiokinetic, hidecategories = (Advanced, Attachment, Volume), BlueprintType, meta = (BlueprintSpawnableComponent))
class AKAUDIO_API UAkPortalComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkPortalComponent")
	void OpenPortal();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkPortalComponent")
	void ClosePortal();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkPortalComponent")
	AkAcousticPortalState GetCurrentState() const;

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkPortalComponent")
	UPrimitiveComponent* GetPrimitiveParent() const;

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkPortalComponent")
	bool PortalPlacementValid() const { return GetFrontRoom() != GetBackRoom(); }

	/** If true, the room connections for this portal can change during runtime when this portal moves. For worlds containing many rooms, this can be expensive. Note that this portal's room connections may still change, even when bDynamic = false, when dynamic rooms are moved (i.e. when rooms move who have bDynamic = true). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkPortalComponent", meta = (DisplayName = "Is Dynamic"))
	bool bDynamic = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AkPortalComponent")
	AkAcousticPortalState InitialState = AkAcousticPortalState::Open;

	/** Time interval between obstruction checks (direct line of sight between listener and portal opening). Set to 0 to disable obstruction checks. We recommend disabling it if you want to use full Spatial Audio diffraction. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkPortalComponent|Obstruction")
	float ObstructionRefreshInterval;

	/** Collision channel for obstruction checks (between listener and portal opening). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkPortalComponent|Obstruction")
	TEnumAsByte<ECollisionChannel> ObstructionCollisionChannel = ECollisionChannel::ECC_Visibility;

	void ResetPortalState();

	FVector GetExtent() const;
	AkRoomID GetFrontRoom() const;
	AkRoomID GetBackRoom() const;
	AkPortalID GetPortalID() const { return AkPortalID(this); }

	/** Update the room connections for the portal, given the portals current transform. 
		Return true if the room connections have changed.
	*/
	bool UpdateConnectedRooms();

	const UAkRoomComponent* GetFrontRoomComponent() const { return FrontRoom; }
	const UAkRoomComponent* GetBackRoomComponent() const { return BackRoom; }

	virtual void BeginPlay() override;
#if WITH_EDITOR
	virtual void BeginDestroy() override;
	virtual void InitializeComponent() override;
	virtual void OnComponentCreated() override;
	virtual void PostLoad() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
#endif // WITH_EDITOR
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) override;
	virtual bool MoveComponentImpl(
		const FVector & Delta,
		const FQuat & NewRotation,
		bool bSweep,
		FHitResult * Hit,
		EMoveComponentFlags MoveFlags,
		ETeleportType Teleport) override;

private:
	class UPrimitiveComponent* Parent;

	void InitializeParent();
	void SetSpatialAudioPortal();

	template <typename tComponent>
	void FindConnectedComponents(FAkEnvironmentIndex& RoomQuery, tComponent*& out_pFront, tComponent*& out_pBack);

	AkAcousticPortalState PortalState;

#if WITH_EDITOR
	static const float RoomsRefreshIntervalEditor;
#endif
	static const float RoomsRefreshIntervalGame;
	static const float RoomsRefreshDistanceThreshold;
	static const float RoomsRefreshMinRotationThreshold_Degrees;
	float RoomsRefreshIntervalSeconds = 0.5f;
	float LastRoomsUpdate = 0.0f;
	FVector PreviousLocation;
	FRotator PreviousRotation;

	bool PortalNeedUpdated = false;
	UAkRoomComponent* FrontRoom;
	UAkRoomComponent* BackRoom;

	AkPortalOcclusionObstructionService ObstructionService;

#if WITH_EDITOR
	void HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);
	class UDrawPortalComponent* DrawPortalComponent = nullptr;
	void RegisterVisEnabledCallback();
	void InitializeDrawComponent();
	void DestroyDrawComponent();
	FDelegateHandle ShowPortalsChangedHandle;
#endif
};

UCLASS(ClassGroup = Audiokinetic, hidecategories = (Advanced, Attachment, Volume), BlueprintType)
class AKAUDIO_API AAkAcousticPortal : public AVolume
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkAcousticPortal")
	void OpenPortal();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkAcousticPortal")
	void ClosePortal();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkAcousticPortal")
	AkAcousticPortalState GetCurrentState() const;

	AkRoomID GetFrontRoom() const;
	AkRoomID GetBackRoom() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal", meta = (ShowOnlyInnerProperties))
	UAkPortalComponent* Portal;

	virtual void PostRegisterAllComponents() override;
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

#if WITH_EDITOR
	void FitRaycast();
	void FitPortal();
	virtual void PostEditMove(bool bFinished) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	bool GetBestHits(FVector& Start0, FVector& End0, FVector& Start1, FVector& End1) 
	{ 
		if (BestFitValid)
		{
			Start0 = BestFit[0];
			End0 = BestFit[1];
			Start1 = BestFit[2];
			End1 = BestFit[3];
			
			return true;
		}
		return false;
	}
	float GetDetectionRadius() const { return DetectionRadius; }
	bool GetFitToGeometry() const { return FitToGeometry; }
	bool GetIsDragging() const { return IsDragging;  }

	virtual FName GetCustomIconName() const override
	{
		static const FName IconName("ClassIcon.AkAcousticPortal");
		return IconName;
	}
#endif

protected:
	static const int kNumRaycasts = 128;

#if WITH_EDITORONLY_DATA
	void ClearBestFit();

	/**
	Automatically fit the Ak Acoustic Portal to surrounding geometry. The fitting operation is performed after enabling this property, or after moving the actor to a new location.
	To find portals in surrounding geometry, rays emanating spherically outwards are cast from the origin of the actor in an attempt to detect sets of parallel surfaces.
	The "best" detected parallel surfaces are indicated with yellow outline when dragging the actor to a new location.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry")
	bool FitToGeometry = false;

	/**
	Set the collision channel for the ray traces performed to fit the portal to the surrounding geometry. The default value for the collision channel is specified in the Wwise integration settings.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	/**
	Limits the effective portal opening size that can be detected when fitting the portal to surrounding geometry.
	Increase this value to find larger openings; decrease it if large portals are erroneously detected, for example ones that span whole rooms.
	The slider range can be expanded by entering a text value into this field.
	*/
	UPROPERTY(EditAnywhere, Category = "Fit to Geometry", meta = (ClampMin = 1.0f, ClampMax = 100000.0f, UIMin = 100.0f, UIMax = 5000.0f))
	float DetectionRadius = 500.0f;

	FVector SavedRaycastOrigin;
	bool bUseSavedRaycastOrigin = false;
	FVector BestFit[4];
	bool BestFitValid = false;
	bool IsDragging = false;
#endif

private:
	/** As of Wwise 2020.1, the InitialState is contained in the AkPortalComponent */
	UPROPERTY()
	AkAcousticPortalState InitialState;

	UPROPERTY(Transient)
	bool bRequiresStateMigration = false;
	bool bRequiresTransformMigration = false;
};
