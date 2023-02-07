#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersOverride.h"
#include "ExpHeightFogDirectionalInscatteringParametersOverride.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogSecondParametersOverride.h"
#include "ExpHeightFogVolumetricNoiseParametersOverride.h"
#include "ExpHeightFogVolumetricParametersOverride.h"
#include "ExpHeightFogParamsOverrideFog.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideFog : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersOverride Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersOverride DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersOverride VolumetricFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersOverride VolumetricNoise;
    
    UExpHeightFogParamsOverrideFog();
};

