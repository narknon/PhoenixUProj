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
	AkComponent.h:
=============================================================================*/

#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "AkInclude.h"
#include "AkGameplayTypes.h"
#include "Components/SceneComponent.h"
#include "OcclusionObstructionService/AkComponentOcclusionObstructionService.h"
#include "AkGameObject.h"
#include "AkComponent.generated.h"

UENUM(Meta = (Bitflags))
enum class EReflectionFilterBits
{
	Wall,
	Ceiling,
	Floor
};

// PostEvent functions need to return the PlayingID (uint32), but Blueprints only work with int32.
// Make sure AkPlayingID is always 32 bits, or else we're gonna have a bad time.
static_assert(sizeof(AkPlayingID) == sizeof(int32), "AkPlayingID is not 32 bits anymore. Change return value of PostEvent functions!");

struct AkReverbFadeControl
{
public:
	uint32 AuxBusId;
	bool bIsFadingOut;
	void* FadeControlUniqueId; 

private:
	float CurrentControlValue;
	float TargetControlValue;
	float FadeRate;
	float Priority;

public:
	AkReverbFadeControl(const class UAkLateReverbComponent& LateReverbComponent);
	void UpdateValues(const class UAkLateReverbComponent& LateReverbComponent);
	bool Update(float DeltaTime);
	void ForceCurrentToTargetValue() { CurrentControlValue = TargetControlValue; }
	AkAuxSendValue ToAkAuxSendValue() const;

	static bool Prioritize(const AkReverbFadeControl& A, const AkReverbFadeControl& B);
};


/*------------------------------------------------------------------------------------
	UAkComponent
------------------------------------------------------------------------------------*/
UCLASS(ClassGroup=Audiokinetic, BlueprintType, Blueprintable, hidecategories=(Transform,Rendering,Mobility,LOD,Component,Activation), AutoExpandCategories=AkComponent, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkComponent: public UAkGameObject
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
	bool bUseSpatialAudio_DEPRECATED;

	int32 ReflectionFilter_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Occlusion")
		TEnumAsByte<ECollisionChannel> OcclusionCollisionChannel;

	/**Enable spot reflectors for this Ak Component **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Spatial Audio")
		uint32 EnableSpotReflectors : 1;

	/**
	*	Define an outer radius around each sound position to simulate a radial sound source.
	*	If the listener is outside the outer radius, the spread is defined by the area that the sphere takes in the listener field of view.
	*	When the listener intersects the outer radius, the spread is exactly 50%. When the listener is in between the inner and outer radius, the spread interpolates linearly from 50% to 100%.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AkComponent|Spatial Audio|Radial Emitter", meta = (ClampMin = 0.0f) )
	float outerRadius;

	/**
	*	Define an inner radius around each sound position to simulate a radial sound source.
	*	If the listener is inside the inner radius, the spread is 100%.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AkComponent|Spatial Audio|Radial Emitter", meta = (ClampMin = 0.0f))
	float innerRadius;

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent")
	void SetGameObjectRadius(float in_outerRadius, float in_innerRadius);

private:
	/** 
	*	Send to an Auxiliary Bus containing the Wwise Reflect plugin for early reflections rendering.
	*	Note that the Wwise Auxiliary Bus for early reflections can also be set per-sound in the Sound Property Editor in the Wwise Authoring tool. 
	*	Setting a value here will apply only to sounds playing on the AK Component that do not have an Auxiliary Bus set in the Wwise Authoring tool.
	*/
	UPROPERTY(EditAnywhere, Category = "AkComponent|Spatial Audio|Reflect")
	class UAkAuxBus * EarlyReflectionAuxBus;

	/**
	*	Send to an Auxiliary Bus containing the Wwise Reflect plugin for early reflections rendering.
	*	Note that the Wwise Auxiliary Bus for early reflections can also be set per-sound in the Sound Property Editor in the Wwise Authoring tool.
	*	Setting a value here will apply only to sounds playing on the AK Component that do not have an Auxiliary Bus set in the Wwise Authoring tool.
	*/
	UPROPERTY(EditAnywhere, Category = "AkComponent|Spatial Audio|Reflect")
	FString EarlyReflectionAuxBusName;

	/** As of 2019.2, the Reflection Order is set in the Spatial Audio Initialization Settings in Project Settings */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Reflect (DEPRECATED)", meta = (ClampMin = "0", ClampMax = "4"))
	int EarlyReflectionOrder;

	/**
	*	Set the send volume for the early reflections Auxiliary Bus.
	*	The send volume applied to this AK Component will be applied additively to the Auxiliary Send volume defined per-sound in the Wwise Authoring tool.
	*/
	UPROPERTY(EditAnywhere, Category = "AkComponent|Spatial Audio|Reflect", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float EarlyReflectionBusSendGain;

	/** As of 2019.2, the Reflection Max Path Length is set by the sound's Attenuation Max Distance value in the Authoring */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Reflect (DEPRECATED)", meta = (ClampMin = "0.0"))
	float EarlyReflectionMaxPathLength;

	/** As of 2019.2, the Room Reverb Aux Bus Gain is set by the Game-Defined Auxiliary Sends Volume in the Sound Property Editor in the Authoring */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Room (DEPRECATED)", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float roomReverbAuxBusGain;

	/** As of 2019.2, diffraction is enabled in the Sound Property Editor in the Authoring */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Geometric Diffraction (DEPRECATED)", meta = (ClampMin = "0"))
	int diffractionMaxEdges;

	/** As of 2019.2, diffraction is enabled in the Sound Property Editor in the Authoring */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Geometric Diffraction (DEPRECATED)", meta = (ClampMin = "0"))
	int diffractionMaxPaths;

	/** As of 2019.2, diffraction is enabled in the Sound Property Editor in the Authoring */
	UPROPERTY(VisibleAnywhere, Category = "AkComponent|Spatial Audio|Geometric Diffraction (DEPRECATED)", meta = (ClampMin = "0.0"))
	float diffractionMaxPathLength;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Spatial Audio|Debug Draw")
	uint32 DrawFirstOrderReflections : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Spatial Audio|Debug Draw")
	uint32 DrawSecondOrderReflections : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Spatial Audio|Debug Draw")
	uint32 DrawHigherOrderReflections : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Spatial Audio|Debug Draw")
	uint32 DrawDiffraction : 1;

	/** Stop sound when owner is destroyed? */
	UPROPERTY()
	bool StopWhenOwnerDestroyed;

	/**
	 * Posts this component's AkAudioEvent to Wwise, using this component as the game object source, and wait until the event is 
	 * done playing to continue execution. Extra calls while the event is playing are ignored.
	 *
	 */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent", meta = (AdvancedDisplay = "0", Latent, LatentInfo = "LatentInfo", AutoCreateRefTerm = "ExternalSources"))
	int32 PostAssociatedAkEventAndWaitForEnd(const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent", meta = (AdvancedDisplay = "1", Latent, LatentInfo = "LatentInfo", AutoCreateRefTerm = "ExternalSources"))
	void PostAssociatedAkEventAndWaitForEndAsync(int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);

	AK_DEPRECATED(2019.1.2, "This function is deprecated and will be removed in future releases.")
	int32 PostAssociatedAkEventAndWaitForEnd(FLatentActionInfo LatentInfo);

	/**
	* Posts an event to Wwise, using this component as the game object source, and wait until the event is
	* done playing to continue execution. Extra calls while the event is playing are ignored.
	*
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent", meta = (AdvancedDisplay = "1", Latent, LatentInfo = "LatentInfo", AutoCreateRefTerm = "ExternalSources"))
	int32 PostAkEventAndWaitForEnd(
		class UAkAudioEvent * AkEvent,
		const FString& in_EventName,
		const TArray<FAkExternalSourceInfo>& ExternalSources,
		FLatentActionInfo LatentInfo
	);

	/**
	* Posts an event to Wwise, using this component as the game object source, and wait until the event is
	* done playing to continue execution. Extra calls while the event is playing are ignored.
	*/
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent", meta = (AdvancedDisplay = "2", Latent, LatentInfo = "LatentInfo", AutoCreateRefTerm = "ExternalSources"))
	void PostAkEventAndWaitForEndAsync(
			class UAkAudioEvent* AkEvent,
			int32& PlayingID,
			const TArray<FAkExternalSourceInfo>& ExternalSources,
			FLatentActionInfo LatentInfo
		);

	/**
	 * Posts an event to Wwise using its name, using this component as the game object source
	 *
	 * @param AkEvent		The event to post
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent", meta = (DeprecatedFunction, DeprecationMessage = "Please use the \"Event Name\" field of Post Ak Event"))
	int32 PostAkEventByName( const FString& in_EventName );
	
	AkPlayingID PostAkEventByNameWithDelegate(const FString& in_EventName, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources = TArray<FAkExternalSourceInfo>());
	AkPlayingID PostAkEventByNameWithCallback(const FString& in_EventName, AkUInt32 in_uFlags = 0, AkCallbackFunc in_pfnUserCallback = NULL, void * in_pUserCookie = NULL, const TArray<FAkExternalSourceInfo>& ExternalSources = TArray<FAkExternalSourceInfo>());

	/**
	 * Posts a trigger to wwise, using this component as the game object source
	 *
	 * @param Trigger		The name of the trigger
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent", meta = (AdvancedDisplay = "1"))
	void PostTrigger(class UAkTrigger const* TriggerValue, FString Trigger);
	
	/**
	 * Sets a switch group in wwise, using this component as the game object source
	 *
	 * @param SwitchGroup	The name of the switch group
	 * @param SwitchState	The new state of the switch
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent", meta = (AdvancedDisplay = "1"))
	void SetSwitch(class UAkSwitchValue const* SwitchValue, FString SwitchGroup, FString SwitchState);

	/**
	 * Sets whether or not to stop sounds when the component's owner is destroyed
	 *
	 * @param bStopWhenOwnerDestroyed	Whether or not to stop sounds when the component's owner is destroyed
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent")
	void SetStopWhenOwnerDestroyed( bool bStopWhenOwnerDestroyed );

	/**
	 * Set a game object's listeners
	 *
	 * @param Listeners	The array of components that listen to this component
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent")
	void SetListeners( const TArray<UAkComponent*>& Listeners );

	// Reverb volumes functions

	/**
	 * Set UseReverbVolumes flag. Set value to true to use reverb volumes on this component.
	 *
	 * @param inUseReverbVolumes	Whether to use reverb volumes or not.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent", meta = (DeprecatedFunction, DeprecationMessage = "Please use the \"UseReverbVolume\" property", ScriptName="DEPRECATED_UseReverbVolumes"))
	void UseReverbVolumes(bool inUseReverbVolumes);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkComponent", meta = (AdvancedDisplay = "5", DeprecatedFunction, DeprecationMessage = "This function is deprecated and will be removed in future releases."))
	void UseEarlyReflections(class UAkAuxBus* AuxBus, int Order = 1, float BusSendGain = 1.f, float MaxPathLength = 100000.f, bool SpotReflectors = false, const FString& AuxBusName = FString(""));


	/** 
	* Set the early reflections aux bus for this AK Component.
	* Geometrical reflection calculation inside spatial audio is enabled for a game object if any sound playing on the game object has a valid early reflections aux bus specified in the authoring tool,
	* or if an aux bus is specified via SetEarlyReflectionsAuxSend.
	* The AuxBusName parameter of SetEarlyReflectionsAuxSend applies to sounds playing on the Wwise game object which have not specified an early reflection bus in the authoring tool -
	* the parameter specified on individual sounds' reflection bus takes priority over the value passed in to SetEarlyReflectionsAuxSend.
	* @param AuxBusName - Name of aux bus in the Wwise project.
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkComponent")
	void SetEarlyReflectionsAuxBus(const FString& AuxBusName);

	/** 
	* Set the early reflections volume for this AK Component. The SendVolume parameter is used to control the volume of the early reflections send. It is combined with the early reflections volume specified in the authoring tool,
	* and is applied to all sounds playing on the Wwise game object.
	* @param SendVolume - Send volume to the early reflections aux bus.
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkComponent")
	void SetEarlyReflectionsVolume(float SendVolume);

	/**
	* Set the output bus volume (direct) to be used for the specified game object.
	* The control value is a number ranging from 0.0f to 1.0f.
	*
	* @param BusVolume - Bus volume to set
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkComponent")
	void SetOutputBusVolume(float BusVolume);


	/** Modifies the attenuation computations on this game object to simulate sounds with a a larger or smaller area of effect. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AkComponent")
	float AttenuationScalingFactor;

	/** Sets the attenuation scaling factor, which modifies the attenuation computations on this game object to simulate sounds with a a larger or smaller area of effect. */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkComponent")
	void SetAttenuationScalingFactor(float Value);

	/** Set the time interval between occlusion/obstruction checks (direct line of sight between the listener and this game object). Set to 0 to disable occlusion/obstruction on this component. We recommend disabling it if you want to use full Spatial Audio diffraction. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent|Occlusion")
	float OcclusionRefreshInterval;

	/** Whether to use reverb volumes or not */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AkComponent")
	bool bUseReverbVolumes = true;


	/**
	 * Return the real attenuation radius for this component (AttenuationScalingFactor * AkAudioEvent->MaxAttenuationRadius)
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkComponent")
	float GetAttenuationRadius() const;

	void UpdateGameObjectPosition();

	void GetAkGameObjectName(FString& Name) const;

	bool IsDefaultListener = false;

#if CPP

	/*------------------------------------------------------------------------------------
		UActorComponent interface.
	------------------------------------------------------------------------------------*/
	/**
	 * Called after component is registered
	 */
	virtual void OnRegister();

	/**
	 * Called after component is unregistered
	 */
	virtual void OnUnregister();

	/**
	 * Clean up
	 */
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	/**
	 * Clean up after error
	 */
	virtual void ShutdownAfterError();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	// Begin USceneComponent Interface
	virtual void BeginPlay() override;
	virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport = ETeleportType::None) override;
	// End USceneComponent Interface

	/** Gets all AkLateReverbComponents at the AkComponent's current location, and puts them in a list
	 *
	 * @param Loc					The location of the AkComponent
	 */
	void UpdateAkLateReverbComponentList(FVector Loc);

	/** Gets the current room the AkComponent is in.
	 * 
	 * @param Location			The location of the AkComponent
	 */
	void UpdateSpatialAudioRoom(FVector Location);

	void SetAutoDestroy(bool in_AutoDestroy) { bAutoDestroy = in_AutoDestroy; }

	bool UseDefaultListeners() const { return bUseDefaultListeners; }

	void OnListenerUnregistered(UAkComponent* in_pListener)
	{
		Listeners.Remove(in_pListener);
	}

	void OnDefaultListenerAdded(UAkComponent* in_pListener)
	{
		check(bUseDefaultListeners);
		Listeners.Add(in_pListener);
	}

	const TSet<UAkComponent*>& GetEmitters();

	static UAkComponent* GetAkComponent(AkGameObjectID GameObjectID);

	AkRoomID GetSpatialAudioRoom() const;

	void UpdateOcclusionObstruction() { ObstructionService.UpdateObstructionOcclusion(Listeners, GetPosition(), GetOwner(), GetSpatialAudioRoom(), OcclusionCollisionChannel, OcclusionRefreshInterval); }

	FVector GetPosition() const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	/**
	 * Register the component with Wwise
	 */
	void RegisterGameObject();

	/**
	 * Unregister the component from Wwise
	 */
	void UnregisterGameObject();

	/*
	* Called after registering the component with Wwise
	*/
	virtual void PostRegisterGameObject();

	/*
	* Called after unregistering the component from Wwise
	*/
	virtual void PostUnregisterGameObject();

	// Reverb Volume features ---------------------------------------------------------------------

	/** Apply the current list of AkReverbVolumes 
	 *
	 * @param DeltaTime		The given time increment since last fade computation
	 */
	void ApplyAkReverbVolumeList(float DeltaTime);

	AkComponentOcclusionObstructionService ObstructionService;

	/** Array of the active AkReverbVolumes at the AkComponent's location */
	TArray<AkReverbFadeControl> ReverbFadeControls;

	/** Aux Send values sent to the SoundEngine in the previous frame */
	TArray<AkAuxSendValue> CurrentAuxSendValues;

	/** Do we need to refresh Aux Send values? */
	bool NeedToUpdateAuxSends(const TArray<AkAuxSendValue>& NewValues);

	/** Room the AkComponent is currently in. nullptr if none */
	class UAkRoomComponent* CurrentRoom;

	/** Whether to automatically destroy the component when the event is finished */
	bool bAutoDestroy;

	/** Previous known position. Used to avoid Spamming SetPOsition on a listener */
	AkSoundPosition CurrentSoundPosition;
	bool HasMoved();

#endif

#if WITH_EDITORONLY_DATA
	/** Utility function that updates which texture is displayed on the sprite dependent on the properties of the Audio Component. */
	void UpdateSpriteTexture();
#endif

	bool bUseDefaultListeners;
	TSet<UAkComponent*> Listeners;

	//NOTE: This set of emitters is only valid if this UAkComopnent is a listener, and it it is not a default listener. See GetEmitters().
	TSet<UAkComponent*> Emitters;

	void CheckEmitterListenerConsistancy();

	void DebugDrawReflections() const;
	void _DebugDrawReflections(const AkVector& akEmitterPos, const AkVector& akListenerPos, const AkReflectionPathInfo* paths, AkUInt32 uNumPaths) const;

	void DebugDrawDiffraction() const;
	void _DebugDrawDiffraction(const AkVector& akEmitterPos, const AkVector& akListenerPos, const AkDiffractionPathInfo* paths, AkUInt32 uNumPaths) const;
};
