#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogVolumetricAdvancedParametersRelative.h"
#include "ExpHeightFogParamsRelativeVolumetricAdvanced.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsRelativeVolumetricAdvanced : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParametersRelative VolumetricAdvanced;
    
    UExpHeightFogParamsRelativeVolumetricAdvanced();
};

