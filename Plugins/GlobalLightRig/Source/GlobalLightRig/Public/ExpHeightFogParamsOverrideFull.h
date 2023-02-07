#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParametersOverride.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsOverrideFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsOverrideFull : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParametersOverride Parameters;
    
    UExpHeightFogParamsOverrideFull();
};

