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

#include "AkGameplayTypes.h"

#include "AkReverbDescriptor.generated.h"

class UAkAcousticTextureSetComponent;
class UAkLateReverbComponent;
class UAkRoomComponent;

#define PARAM_ESTIMATION_UPDATE_PERIOD 0.1f

/**
 * FAkReverbDescriptor is used to estimate the reverb parameters of a primitive component, by calculating its volume and surface area, and using the 'sabine equation' to estimate the reverb tail.
 * It also estimates the Time to First Reflection and the HFDamping.
 */
USTRUCT()
struct AKAUDIO_API FAkReverbDescriptor
{
	GENERATED_USTRUCT_BODY()
public:
	static double TriangleArea(const FVector& v1, const FVector& v2, const FVector& v3);

	float PrimitiveVolume = 0.0f;
	float PrimitiveSurfaceArea = 0.0f;
	float T60Decay = 0.0f;
	float HFDamping = 0.0f;
	float TimeToFirstReflection = 0.0f;
	
	bool ShouldEstimateDecay() const;
	bool ShouldEstimateDamping() const;
	bool ShouldEstimatePredelay() const;
	bool RequiresUpdates() const;

	void CalculateT60();
	void CalculateTimeToFirstReflection();
	void CalculateHFDamping(const UAkAcousticTextureSetComponent* textureSetComponent);
	
	void SetPrimitive(UPrimitiveComponent* primitive);
	void SetReverbComponent(UAkLateReverbComponent* reverbComp);

	void UpdateAllRTPCs(const UAkRoomComponent* room) const;

private:
	UPrimitiveComponent* Primitive;
	UAkLateReverbComponent* ReverbComponent;
	/* Looks for a room component attached to Primitive, whose room ID has been registered with wwise, and whose world is Game or PIE.
		room will be null if no such room is found, or if there is no valid AkAudioDevice.
		return true if a room is found (and there is a valid AkAudioDevice). */
	bool GetRTPCRoom(UAkRoomComponent*& room) const;
	bool CanSetRTPCOnRoom(const UAkRoomComponent* room) const;
	void UpdateDecayRTPC() const;
	void UpdateDampingRTPC() const;
	void UpdatePredelaytRTPC() const;

};
