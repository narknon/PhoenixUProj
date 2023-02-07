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
#include "AkAudioDevice.h"
#include "AkReverbDescriptor.h"
#include "GameFramework/Volume.h"
#include "AkGameObject.h"
#include "AkRoomComponent.generated.h"

class UAkLateReverbComponent;

UCLASS(ClassGroup = Audiokinetic, BlueprintType, hidecategories = (Transform, Rendering, Mobility, LOD, Component, Activation, Tags), meta = (BlueprintSpawnableComponent))
class AKAUDIO_API UAkRoomComponent : public UAkGameObject
{
	GENERATED_UCLASS_BODY()

	/** 
	* Enable room transmission feature. Additional properties are available in the Room category. 
	* If Enable Room begins as false, changing Enable Room during runtime will only have an effect
	* if Room Is Dynamic = true.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Toggle, meta = (DisplayName = "Enable Room"))
	uint32 bEnable:1;

	/** 
	* If true, the portal connections for this room can change during runtime when this room moves.
	* For worlds containing many portals, this can be expensive. Note that this room's portal connections 
	* may still change, even when Room Is Dynamic = false, when dynamic portals are moved (i.e. when portals
	* move who have bDynamic = true).
	* When Room Is Dynamic = true, enabling and disabling rooms will have immediate effect, without needing
	* to update emitters and/or listeners directly. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Toggle, meta = (DisplayName = "Room Is Dynamic"))
	bool bDynamic = false;

	/**
	* The precedence in which the Rooms will be applied. In the case of overlapping rooms, only the one
	* with the highest priority is chosen. If two or more overlapping rooms have the same
	* priority, the chosen room is unpredictable.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room")
	float Priority;

	/**
	* Used to set the transmission loss value in wwise, on emitters in the room, when no audio paths to the 
	* listener are found via sound propagation in Wwise Spatial Audio. This value can be thought of as 
	* 'thickness', as it relates to how much sound energy is transmitted through the wall. Valid range 0.0f-1.0f, 
	* and is mapped to the occlusion curve as defined in the Wwise project.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Transmission Loss", Category = "Room", meta = (ClampMin=0.0f, ClampMax=1.0f, UIMin=0.0f, UIMax=1.0f))
	float WallOcclusion;

	/**
	* Send level for sounds that are posted on the room. Valid range: (0.f-1.f). A value of 0 disables the aux send.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkEvent", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float AuxSendLevel;

	/** Automatically post the associated AkAudioEvent on BeginPlay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkEvent", SimpleDisplay)
	bool AutoPost;

	/** Posts this game object's AkAudioEvent to Wwise, using this as the game object source */
	virtual int32 PostAssociatedAkEvent(
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources
	);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkRoomComponent")
	UPrimitiveComponent* GetPrimitiveParent() const;

	/** Register a room in AK Spatial Audio. */
	void AddSpatialAudioRoom();

	/** Modify a room in AK Spatial Audio. */
	void UpdateSpatialAudioRoom();

	/** Remove a room from AK Spatial Audio	*/
	void RemoveSpatialAudioRoom();

	bool HasEffectOnLocation(const FVector& Location) const;

	bool RoomIsActive() const;

	AkRoomID GetRoomID() const { return AkRoomID(this); }

	virtual void OnRegister() override;
	virtual void OnUnregister() override;
#if WITH_EDITOR
	virtual void BeginDestroy() override;
	virtual void OnComponentCreated() override;
	virtual void InitializeComponent() override;
	virtual void PostLoad() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
#endif
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) override;
	virtual bool MoveComponentImpl(
		const FVector & Delta,
		const FQuat & NewRotation,
		bool bSweep,
		FHitResult * Hit,
		EMoveComponentFlags MoveFlags,
		ETeleportType Teleport) override;

	FName GetName() const;

	virtual AkPlayingID PostAkEventByNameWithDelegate(
		const FString& in_EventName,
		int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources = TArray<FAkExternalSourceInfo>());

	// Begin USceneComponent Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	/** Set the geometry component that will be used to send the geometry of the room to Wwise. For example, in a Blueprint that has a static mesh component with an AkGeometry child component, this function can be called in BeginPlay to associate that AkGeometry component with this room component.
	 *  If this room component has a sibling geometry component (or surface reflector set component), they will be associated automatically and there is no need to call this function.
	 */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkRoomComponent")
	void SetGeometryComponent(UAkAcousticTextureSetComponent* textureSetComponent);

private:
	class UPrimitiveComponent* Parent;

	UPROPERTY(Transient)
	class UAkAcousticTextureSetComponent* GeometryComponent;

	void InitializeParent();
	void GetRoomParams(AkRoomParams& outParams);
	bool EncompassesPoint(FVector Point, float SphereRadius = 0.f, float* OutDistanceToPoint = nullptr) const;
	void BeginPlayInternal();
	void SendGeometry();
	void RemoveGeometry();
	float SecondsSinceMovement = 0.0f;
	bool Moving = false;
#if WITH_EDITOR
	void HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);
	bool bRequiresDeferredBeginPlay = false;
	class UDrawRoomComponent* DrawRoomComponent = nullptr;
	void RegisterVisEnabledCallback();
	void InitializeDrawComponent();
	void DestroyDrawComponent();
	FDelegateHandle ShowRoomsChangedHandle;
#endif
};
