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
	AkGameObject.h:
=============================================================================*/

#pragma once

#include "AkAudioDevice.h"
#include "Components/SceneComponent.h"
#include "AkGameObject.generated.h"


UCLASS(ClassGroup=Audiokinetic, BlueprintType, Blueprintable, hidecategories=(Transform,Rendering,Mobility,LOD,Component,Activation), AutoExpandCategories=AkComponent, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkGameObject: public USceneComponent
{
	GENERATED_UCLASS_BODY()

public:
	/** Wwise Event to be posted on this game object */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AkEvent")
	UAkAudioEvent* AkAudioEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "AkEvent")
	FString EventName;

	/**
	 * Posts this game object's AkAudioEvent to Wwise, using this as the game object source
	 *
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkGameObject", meta = (AdvancedDisplay = "2", AutoCreateRefTerm = "PostEventCallback,ExternalSources"))
	virtual int32 PostAssociatedAkEvent(
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources
	);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkGameObject", meta = (AutoCreateRefTerm = "PostEventCallback,ExternalSources", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject"))
	virtual void PostAssociatedAkEventAsync(const UObject* WorldContextObject,
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources,
		FLatentActionInfo LatentInfo,
		int32& PlayingID);

	AK_DEPRECATED(2019.1.2, "This function is deprecated and will be removed in future releases.")
	virtual int32 PostAssociatedAkEvent(
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback
	);

	/**
	 * Posts an event to Wwise, using this as the game object source
	 *
	 * @param AkEvent		The event to post
	 * @param CallbackMask	Mask of desired callbacks
	 * @param PostEventCallback	Blueprint Event to execute on callback
	 *
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkGameObject", meta = (AdvancedDisplay = "1", AutoCreateRefTerm = "PostEventCallback,ExternalSources"))
	virtual int32 PostAkEvent(
		class UAkAudioEvent * AkEvent,
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources,
		const FString& in_EventName
	);

	/**
	 * Posts an event to Wwise, using this as the game object source
	 *
	 * @param AkEvent		The event to post
	 * @param CallbackMask	Mask of desired callbacks
	 * @param PostEventCallback	Blueprint Event to execute on callback
	 *
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkGameObject", meta = (AdvancedDisplay = "3", AutoCreateRefTerm = "PostEventCallback,ExternalSources", Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject"))
	virtual void PostAkEventAsync(const UObject* WorldContextObject,
			class UAkAudioEvent* AkEvent,
			int32& PlayingID,
			UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
			const FOnAkPostEventCallback& PostEventCallback,
			const TArray<FAkExternalSourceInfo>& ExternalSources,
			FLatentActionInfo LatentInfo
	);

	AK_DEPRECATED(2019.1.2, "This function is deprecated and will be removed in future releases.")
	virtual int32 PostAkEvent(
		class UAkAudioEvent * AkEvent,
		UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const FString& in_EventName
	);

	/**
	 * Stops playback using this game object as the game object to stop
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkComponent")
	virtual void Stop();

	virtual AkPlayingID PostAkEventByNameWithDelegate(
		const FString& in_EventName,
		int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources = TArray<FAkExternalSourceInfo>());

	virtual void PostAkEventAsyncByEvent(const UObject* WorldContextObject,
		class UAkAudioEvent* AkEvent,
		int32 CallbackMask,
		const FOnAkPostEventCallback& PostEventCallback,
		const TArray<FAkExternalSourceInfo>& ExternalSources,
		FLatentActionInfo LatentInfo,
		int32& PlayingID
	);

	/**
	* Sets an RTPC value, using this game object as the game object source
	*
	* @param RTPC			The name of the RTPC to set
	* @param Value			The value of the RTPC
	* @param InterpolationTimeMs - Duration during which the RTPC is interpolated towards Value (in ms)
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkGameObject", meta = (AdvancedDisplay = "3"))
	void SetRTPCValue(class UAkRtpc const* RTPCValue, float Value, int32 InterpolationTimeMs, FString RTPC) const;

	/**
	* Gets an RTPC value that was set on this game object as the game object source
	*
	* @param RTPC				The name of the RTPC to set
	* @param InputValueType		The input value type
	* @param Value				The value of the RTPC
	* @param OutputValueType	The output value type
	* @param PlayingID			The playing ID of the posted event (Set to zero to ignore)
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|AkGameObject", meta = (AdvancedDisplay = "RTPC"))
	void GetRTPCValue(class UAkRtpc const* RTPCValue, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, FString RTPC, int32 PlayingID = 0) const;
	AK_DEPRECATED(2019.1.3, "This function is deprecated and will be removed in future releases.")
	void GetRTPCValue(FString RTPC, int32 PlayingID, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType) const;

#if CPP
	bool VerifyEventName(const FString& in_EventName) const;
	bool AllowAudioPlayback() const;
	AkGameObjectID GetAkGameObjectID() const;
	virtual void UpdateOcclusionObstruction() {};
	bool HasActiveEvents() const;
#endif

	bool HasBeenRegisteredWithWwise() const { return IsRegisteredWithWwise; }

protected:
	/** Whether an event was posted on the game object. Never reset to false. */
	bool bStarted;
	bool IsRegisteredWithWwise = false;
};
