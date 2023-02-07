#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogBasicParametersOverride.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsOverrideBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideBasic : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersOverride Basic;
    
    UExpHeightFogParamsOverrideBasic();
};

