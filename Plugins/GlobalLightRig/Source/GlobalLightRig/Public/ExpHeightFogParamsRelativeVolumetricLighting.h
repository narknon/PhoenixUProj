#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogVolumetricLightingParametersRelative.h"
#include "ExpHeightFogParamsRelativeVolumetricLighting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeVolumetricLighting : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricLightingParametersRelative VolumetricLighting;
    
    UExpHeightFogParamsRelativeVolumetricLighting();
};

