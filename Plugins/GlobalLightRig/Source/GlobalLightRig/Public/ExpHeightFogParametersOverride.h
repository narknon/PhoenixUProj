#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersOverride.h"
#include "ExpHeightFogDirectionalInscatteringParametersOverride.h"
#include "ExpHeightFogInscatteringTextureParametersOverride.h"
#include "ExpHeightFogSecondParametersOverride.h"
#include "ExpHeightFogVolumetricAdvancedParametersOverride.h"
#include "ExpHeightFogVolumetricLightingParametersOverride.h"
#include "ExpHeightFogVolumetricNoiseParametersOverride.h"
#include "ExpHeightFogVolumetricParametersOverride.h"
#include "ExpHeightFogParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogParametersOverride {
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParametersOverride VolumetricAdvanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogInscatteringTextureParametersOverride InscatteringTexture;
    
    FExpHeightFogParametersOverride();
};

