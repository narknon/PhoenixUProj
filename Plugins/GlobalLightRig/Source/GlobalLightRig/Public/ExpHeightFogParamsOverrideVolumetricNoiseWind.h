#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsOverrideVolumetricNoiseWind.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideVolumetricNoiseWind : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AddWindVelocity;
    
    UExpHeightFogParamsOverrideVolumetricNoiseWind();
};

