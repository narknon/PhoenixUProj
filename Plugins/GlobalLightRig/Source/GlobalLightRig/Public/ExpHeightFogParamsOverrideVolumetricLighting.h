#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogVolumetricLightingParametersOverride.h"
#include "ExpHeightFogParamsOverrideVolumetricLighting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideVolumetricLighting : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricLightingParametersOverride VolumetricLighting;
    
    UExpHeightFogParamsOverrideVolumetricLighting();
};

