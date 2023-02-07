#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogVolumetricAdvancedParametersOverride.h"
#include "ExpHeightFogParamsOverrideVolumetricAdvanced.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideVolumetricAdvanced : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParametersOverride VolumetricAdvanced;
    
    UExpHeightFogParamsOverrideVolumetricAdvanced();
};

