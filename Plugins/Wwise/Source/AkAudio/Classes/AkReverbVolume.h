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
#include "AkLateReverbComponent.h"
#include "AkReverbVolume.generated.h"

/*------------------------------------------------------------------------------------
	AAkReverbVolume
------------------------------------------------------------------------------------*/
UCLASS(hidecategories=(Advanced, Attachment, Volume), BlueprintType)
class AKAUDIO_API AAkReverbVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
	virtual FName GetCustomIconName() const override
	{
		static const FName IconName("ClassIcon.AkReverbVolume");
		return IconName;
	}
#endif

	/** Whether this volume is currently enabled and able to affect sounds */
	UPROPERTY()
	uint32 bEnabled_DEPRECATED:1;

	UPROPERTY()
	class UAkAuxBus * AuxBus_DEPRECATED;

	/** Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY()
	FString AuxBusName_DEPRECATED;

	/** Maximum send level to the Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY()
	float SendLevel_DEPRECATED;

	/** Rate at which to fade in/out the SendLevel of the current Reverb Volume when entering/exiting it, in percentage per second (0.2 will make the fade time 5 seconds) */
	UPROPERTY()
	float FadeRate_DEPRECATED;

	/**
	 * The precedence in which the AkReverbVolumes will be applied. In the case of overlapping volumes, only the ones 
	 * with the highest priority are chosen (the number of simultaneous AkReverbVolumes is configurable in the Unreal 
	 * Editor Project Settings under Plugins > Wwise). If two or more overlapping AkReverbVolumes have the same 
	 * priority, the chosen AkReverbVolume is unpredictable.
	 */
	UPROPERTY()
	float Priority_DEPRECATED;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "LateReverb", meta = (ShowOnlyInnerProperties))
	UAkLateReverbComponent* LateReverbComponent;

	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;
};
