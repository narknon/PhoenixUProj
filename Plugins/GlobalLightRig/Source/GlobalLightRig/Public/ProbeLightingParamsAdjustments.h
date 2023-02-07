#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingAdjustmentParameters.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsAdjustments.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsAdjustments : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParameters Parameters;
    
    UProbeLightingParamsAdjustments();
};

