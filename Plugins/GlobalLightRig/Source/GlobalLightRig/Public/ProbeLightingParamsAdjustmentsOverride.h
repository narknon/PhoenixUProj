#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingAdjustmentParametersOverride.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsAdjustmentsOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsAdjustmentsOverride : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParametersOverride Parameters;
    
    UProbeLightingParamsAdjustmentsOverride();
};

