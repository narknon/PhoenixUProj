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
#include "AkInclude.h"
#include "AkSettings.h"
#include "AkAcousticTexture.h"
#include "Components/SceneComponent.h"
#include "AkAcousticTextureSetComponent.generated.h"

struct FAkReverbDescriptor;

UCLASS(ClassGroup = Audiokinetic, abstract)
class AKAUDIO_API UAkAcousticTextureSetComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual void GetTexturesAndSurfaceAreas(TArray<FAkAcousticTextureParams>& textures, TArray<float>& surfaceAreas) const { check(0 && "This function must be overidden"); }

	void SetReverbDescriptor(FAkReverbDescriptor* reverbDescriptor);

	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual AkGeometrySetID GetGeometrySetID() const { return AkGeometrySetID(this); }

protected:
	void RecalculateHFDamping();
#if WITH_EDITOR
	virtual void BeginDestroy() override;
	virtual void HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);
	void RegisterReverbRTPCChangedCallback();
	FDelegateHandle RTPCChangedHandle;
	virtual void RegisterAllTextureParamCallbacks() { check(0 && "This function must be overidden"); }
	void RegisterTextureParamChangeCallback(FGuid textureID);
	void UnregisterTextureParamChangeCallbacks();
	/* Register param changed callbacks for any textures that have not been registered. Called when the AcousticPolys array is updated */
	TMap<FGuid, FDelegateHandle> TextureDelegateHandles;
#endif

	FAkReverbDescriptor* ReverbDescriptor = nullptr;
	bool DampingEstimationNeedsUpdate = false;

	virtual bool ShouldSendGeometry() const;
	void SendGeometryToWwise(const AkGeometryParams& params);
	void RemoveGeometryFromWwise();

private:
#if WITH_EDITOR
	virtual bool ContainsTexture(const FGuid& textureID)
	{
		check(0 && "This function must be overidden");
		return false;
	}
#endif

	float SecondsSinceDampingUpdate = 0.0f;

	bool GeometryHasBeenSent = false;
};
