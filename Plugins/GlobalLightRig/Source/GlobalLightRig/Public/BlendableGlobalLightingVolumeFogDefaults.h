#pragma once
#include "CoreMinimal.h"
#include "BlendableGlobalLightingVolumeFogDefaultsBase.h"
#include "ExpHeightFogBasicParametersOverride.h"
#include "ExpHeightFogDirectionalInscatteringParametersOverride.h"
#include "ExpHeightFogSecondParametersOverride.h"
#include "ExpHeightFogVolumetricLightingParametersOverride.h"
#include "ExpHeightFogVolumetricNoiseParametersOverride.h"
#include "ExpHeightFogVolumetricParametersOverride.h"
#include "BlendableGlobalLightingVolumeFogDefaults.generated.h"

UCLASS(Blueprintable)
class UBlendableGlobalLightingVolumeFogDefaults : public UBlendableGlobalLightingVolumeFogDefaultsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersOverride Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersOverride DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersOverride Volumetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricLightingParametersOverride VolumetricLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersOverride VolumetricNoise;
    
    UBlendableGlobalLightingVolumeFogDefaults();
};

