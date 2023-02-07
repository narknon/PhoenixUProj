#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingToneMapParametersOverride.h"
#include "ProbeLightingParamsToneMapOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsToneMapOverride : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParametersOverride Parameters;
    
    UProbeLightingParamsToneMapOverride();
};

