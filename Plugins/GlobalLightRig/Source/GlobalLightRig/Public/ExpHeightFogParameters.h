#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParameters.h"
#include "ExpHeightFogDirectionalInscatteringParameters.h"
#include "ExpHeightFogInscatteringTextureParameters.h"
#include "ExpHeightFogSecondParameters.h"
#include "ExpHeightFogVolumetricAdvancedParameters.h"
#include "ExpHeightFogVolumetricLightingParameters.h"
#include "ExpHeightFogVolumetricNoiseParameters.h"
#include "ExpHeightFogVolumetricParameters.h"
#include "ExpHeightFogParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParameters Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParameters DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParameters Volumetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricLightingParameters VolumetricLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParameters VolumetricNoise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParameters VolumetricAdvanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogInscatteringTextureParameters InscatteringTexture;
    
    FExpHeightFogParameters();
};

