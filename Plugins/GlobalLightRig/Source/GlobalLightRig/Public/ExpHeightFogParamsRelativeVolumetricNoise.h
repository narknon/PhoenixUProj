#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogVolumetricNoiseParametersRelative.h"
#include "ExpHeightFogParamsRelativeVolumetricNoise.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeVolumetricNoise : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersRelative VolumetricNoise;
    
    UExpHeightFogParamsRelativeVolumetricNoise();
};

