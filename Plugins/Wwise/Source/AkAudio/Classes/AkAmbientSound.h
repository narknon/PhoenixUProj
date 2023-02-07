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
	AkAmbientSound.h:
=============================================================================*/
#pragma once

#include "GameFramework/Actor.h"
#include "AkAmbientSound.generated.h"

/*------------------------------------------------------------------------------------
	AAkAmbientSound
------------------------------------------------------------------------------------*/
UCLASS(config=Engine, hidecategories=Audio, AutoExpandCategories=AkAmbientSound, BlueprintType)
class AKAUDIO_API AAkAmbientSound : public AActor
{
	GENERATED_UCLASS_BODY()


	/** AkAudioEvent to play. Deprecated as UE4.7 integration: Use AkComponent->AkAudioEvent instead */
	UPROPERTY()
	class UAkAudioEvent * AkAudioEvent_DEPRECATED;

	/** AkComponent to handle playback */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AkAmbientSound, meta=(ShowOnlyInnerProperties) )
	class UAkComponent* AkComponent;
	
	/** Stop playback if the owner is destroyed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AkAmbientSound, SimpleDisplay)
	bool StopWhenOwnerIsDestroyed;

	/** Automatically post the associated AkAudioEvent on BeginPlay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AkAmbientSound, SimpleDisplay)
	bool AutoPost;

	/*
	 * Start an Ak ambient sound.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkAmbientSound")
	void StartAmbientSound();

	/*
	 * Stop an Ak ambient sound.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Audiokinetic|AkAmbientSound")
	void StopAmbientSound();


#if CPP
public:

	/**
	 * Start the ambience playback
	 */
	void StartPlaying();

	/**
	 * Stop the ambience playback
	 */
	void StopPlaying();

	/**
	 * Is whether this ambient sound currently playing
	 *
	 * @return		True if ambient sound is currently playing, false if not.
	 */
	bool IsCurrentlyPlaying();


protected:
	/*------------------------------------------------------------------------------------
		AActor interface.
	------------------------------------------------------------------------------------*/

	virtual void BeginPlay() override;

#if WITH_EDITOR
	/**
	 * Check for errors
	 */
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	virtual void PostInitializeComponents() override;
	virtual void PostLoad() override;

#endif

private:
	/** used to update status of toggleable level placed ambient sounds on clients */
	bool CurrentlyPlaying;

	FCriticalSection PlayingCriticalSection;
};
