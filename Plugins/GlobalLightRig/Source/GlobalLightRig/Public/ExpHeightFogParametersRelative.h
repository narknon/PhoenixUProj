#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersRelative.h"
#include "ExpHeightFogDirectionalInscatteringParametersRelative.h"
#include "ExpHeightFogSecondParametersRelative.h"
#include "ExpHeightFogVolumetricAdvancedParametersRelative.h"
#include "ExpHeightFogVolumetricLightingParametersRelative.h"
#include "ExpHeightFogVolumetricNoiseParametersRelative.h"
#include "ExpHeightFogVolumetricParametersRelative.h"
#include "ExpHeightFogParametersRelative.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogParametersRelative {
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
    FExpHeightFogVolumetricLightingParametersRelative VolumetricLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersRelative VolumetricNoise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParametersRelative VolumetricAdvanced;
    
    FExpHeightFogParametersRelative();
};

