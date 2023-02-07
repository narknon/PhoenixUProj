#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersRelative.h"
#include "ExpHeightFogDirectionalInscatteringParametersRelative.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogSecondParametersRelative.h"
#include "ExpHeightFogVolumetricNoiseParametersRelative.h"
#include "ExpHeightFogVolumetricParametersRelative.h"
#include "ExpHeightFogParamsRelativeFog.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeFog : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersRelative Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersRelative Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersRelative DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersRelative VolumetricFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersRelative VolumetricNoise;
    
    UExpHeightFogParamsRelativeFog();
};

