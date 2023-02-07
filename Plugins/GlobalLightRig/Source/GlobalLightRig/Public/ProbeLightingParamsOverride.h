#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingParametersOverride.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsOverride : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingParametersOverride Parameters;
    
    UProbeLightingParamsOverride();
};

