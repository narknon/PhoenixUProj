#pragma once
#include "CoreMinimal.h"
#include "BlendableGlobalLightingVolumeFogDefaultsBase.h"
#include "ExpHeightFogBasicParametersRelative.h"
#include "ExpHeightFogDirectionalInscatteringParametersRelative.h"
#include "ExpHeightFogSecondParametersRelative.h"
#include "ExpHeightFogVolumetricNoiseParametersRelative.h"
#include "ExpHeightFogVolumetricParametersRelative.h"
#include "BlendableGlobalLightingVolumeFogRelativeDefaults.generated.h"

UCLASS(Blueprintable)
class UBlendableGlobalLightingVolumeFogRelativeDefaults : public UBlendableGlobalLightingVolumeFogDefaultsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersRelative Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersRelative Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersRelative DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersRelative Volumetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersRelative VolumetricNoise;
    
    UBlendableGlobalLightingVolumeFogRelativeDefaults();
};

