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
#include "Components/SceneComponent.h"
#include "AkReverbDescriptor.h"

#if WITH_EDITOR
#include "Components/TextRenderComponent.h"
#endif

#include "AkLateReverbComponent.generated.h"

class UAkRoomComponent;
class UAkAcousticTextureSetComponent;

UCLASS(ClassGroup = Audiokinetic, BlueprintType, hidecategories = (Transform, Rendering, Mobility, LOD, Component, Activation, Tags), meta = (BlueprintSpawnableComponent))
class AKAUDIO_API UAkLateReverbComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

public:
	/**
	 * Enable usage of the late reverb inside a volume. Additional properties are available in the Late Reverb category.
	 * The number of simultaneous AkReverbVolumes is configurable in the Unreal Editor Project Settings under Plugins > Wwise
	 * If this Late Reverb is applied to a Spatial Audio room, it will be active even if the maximum number of simultaneous reverb volumes (see integration settings) was reached.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Toggle, meta = (DisplayName = "Enable Late Reverb"))
	uint32 bEnable:1;

	/** Maximum send level to the Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Late Reverb", meta = (ClampMin = 0.0f, ClampMax = 1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float SendLevel;

	/** Rate at which to fade in/out the SendLevel of the current Reverb Volume when entering/exiting it, in percentage per second (0.2 will make the fade time 5 seconds) */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Late Reverb" ,meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float FadeRate;

	/**
	 * The precedence in which the AkReverbVolumes will be applied. In the case of overlapping volumes, only the ones 
	 * with the highest priority are chosen. If two or more overlapping AkReverbVolumes have the same 
	 * priority, the chosen AkReverbVolume is unpredictable. 
	 * If this Late Reverb is applied to a Spatial Audio room, the room's priority will be used instead.
	 * Sound emitted by game objects in a room will always be sent to the room late reverb independently of other late reverbs in the scene.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Late Reverb")
	float Priority;

	/**
	 * When enabled, the aux bus for this reverb component will be assigned automatically. This is done by estimating the decay time of the reverb produced by the parent Primitive Component, given its volume and surface area.
	 * This decay value is used to select an aux bus from the reverb aux bus assignment map in the integration settings.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Late Reverb")
	bool AutoAssignAuxBus = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!AutoAssignAuxBus"), Category = "Late Reverb")
	class UAkAuxBus* AuxBus;

	/** Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (EditCondition = "!AutoAssignAuxBus"), Category = "Late Reverb")
	FString AuxBusName;

	/** Get the AkAuxBusId associated to AuxBusName */
	uint32 GetAuxBusId() const;

	bool HasEffectOnLocation(const FVector& Location) const;

	bool LateReverbIsActive() const { return Parent && bEnable && !IsRunningCommandlet(); }

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual bool MoveComponentImpl(
		const FVector & Delta,
		const FQuat & NewRotation,
		bool bSweep,
		FHitResult * Hit,
		EMoveComponentFlags MoveFlags,
		ETeleportType Teleport) override;
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

#if WITH_EDITOR
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnAttachmentChanged() override;
	void UpdateHFDampingEstimation(float hfDamping);
	void UpdatePredelayEstimation(float predelay);
#endif

	void UpdateDecayEstimation(float decay, float volume, float surfaceArea);
	void UpdateRTPCs(const UAkRoomComponent* room) const;

	/** Set the component that will be used to estimate the HFDamping. For example, in a Blueprint that has a static mesh component with an AkGeometry child component, this function can be called in BeginPlay to associate that AkGeometry component with this reverb component.
	 *  If this late reverb component has a sibling geometry component (or surface reflector set component), they will be associated automatically and there is no need to call this function.
	 */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|LateReverb|Reverb Parameter Estimation")
		void AssociateAkTextureSetComponent(UAkAcousticTextureSetComponent* textureSetComponent);

private:
	friend class FAkAudioDevice;

	class UPrimitiveComponent* Parent;
	
	/** Save the manually assigned aux bus so we can recall it if auto-assign is disabled. */
	UPROPERTY(VisibleAnywhere, Category="Audiokinetic|LateReverb")
	class UAkAuxBus* AuxBusManual;

	/** The component that will be used to estimate the HFDamping value. This will usually be an AkGeometryComponent.
	 *  When the owning Actor is a Volume (as is the case for SpatialAudioVolume) this will be an AkSurfaceReflectorSetComponent.
	 */
	UAkAcousticTextureSetComponent* TextureSetComponent = nullptr;

	// Used to estimate the reverb parameters from the Primitive parent.
	FAkReverbDescriptor ReverbDescriptor;
	// Used to track when the reverb parameters need updated (on register, and when the size changes).
	float SecondsSinceDecayUpdate = 0.0f;
	bool DecayEstimationNeedsUpdate = false;
	float SecondsSincePredelayUpdate = 0.0f;
	bool PredelayEstimationNeedsUpdate = false;	

	// Indicates that the component was added to the spatial index in AkAudioDevice.
	bool IsIndexed = false;

	void RecalculateDecay();
	void RecalculatePredelay();

	void InitializeParent();
	void ParentChanged();
	bool EncompassesPoint(FVector Point, float SphereRadius = 0.f, float* OutDistanceToPoint = nullptr) const;
	// Used to track when the parameters of an Acoustic Texture asset change.
	FDelegateHandle TextureParamChangedHandle;

#if WITH_EDITOR
	void HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);
#endif
#if WITH_EDITORONLY_DATA
	static float TextVisualizerHeightOffset;
	// The text visualizers display the values of the parameter estimations directly in the level (or blueprint editor).
	UPROPERTY(SkipSerialization, NonTransactional)
	UTextRenderComponent* TextVisualizerLabels = nullptr;
	UPROPERTY(SkipSerialization, NonTransactional)
	UTextRenderComponent* TextVisualizerValues = nullptr;
	void UpdateTextVisualizerStatus();
	bool TextVisualizersInitialized() const;
	FText GetValuesLabels() const;
	void DestroyTextVisualizers();
	void InitTextVisualizers();
	void UpdateValuesLabels();
	bool WasSelected = false;

	FVector GetTextVisualizersLocation();

	// Used to track when the Aux bus map, or the global RTPCs in the integration settings change.
	void RegisterAuxBusMapChangedCallback();
	FDelegateHandle AuxBusChangedHandle;
	void RegisterReverbRTPCChangedCallback();
	FDelegateHandle RTPCChangedHandle;

	UPROPERTY(VisibleAnywhere, Category = "Late Reverb|Reverb Parameter Estimation|Primitive Geometry")
	float EnvironmentVolume = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Late Reverb|Reverb Parameter Estimation|Primitive Geometry")
	float SurfaceArea = 0.0f;

	/** An estimation of the T60 (the time taken for the sound pressure level to reduce by 60dB) for the reverb's environment, based on the primitive component to which the late reverb is attached.
	 *  This T60 value can be used to automatically assign an aux bus using the Reverb Assignment Map in the integration settings, and/or to drive the Decay Estimate RTPC, also found in the integration settings.
	 *  In order to use the global reverb RTPCs, the reverb component must have a sibling AkRoomComponent (in other words, a room component attached to the same Primitive parent).
	 */
	UPROPERTY(VisibleAnywhere, Category = "Late Reverb|Reverb Parameter Estimation")
	float EnvironmentDecayEstimate = 0.0f;

	/** This value is driven by the acoustic textures used in an associated AkGeometryComponent or AkSurfaceReflectorSetComponent. It measures the average frequency bias of the damping. In other words, whether there is more high-frequency damping, more low-frequency damping, or uniform damping across frequencies.
	 *  A value of 0.0 indicates uniform damping across all frequencies. A value > 0.0 indicates more damping for higher frequencies than lower frequencies. A value < 0.0 indicates more damping for lower frequencies than high frequencies.
	 *  This value can be used to drive the HFDamping RTPC, found in the integration settings.
	 *  In order to use the global reverb RTPCs, the reverb component must have a sibling AkRoomComponent (in other words, a room component attached to the same Primitive parent).
	 */
	UPROPERTY(VisibleAnywhere, Category = "Late Reverb|Reverb Parameter Estimation")
	float HFDamping = 0.0f;

	/** An estimation of the time taken for the first reflection to reach the listener, based on the primitive component to which the late reverb is attached.
	 *  This is estimated based on an emitter and listener being positioned at the centre of the parent primitive component. This value can be used to drive the Time To First Reflection RTPC, found in the integration settings.
	 *  In order to use the global reverb RTPCs, the reverb component must have a sibling AkRoomComponent (in other words, a room component attached to the same Primitive parent).
	 */
	UPROPERTY(VisibleAnywhere, Category = "Late Reverb|Reverb Parameter Estimation")
	float TimeToFirstReflection = 0.0f;
#endif
};
