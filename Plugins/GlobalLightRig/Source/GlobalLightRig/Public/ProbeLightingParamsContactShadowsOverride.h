#pragma once
#include "CoreMinimal.h"
#include "ProbeContactShadowsParametersOverride.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsContactShadowsOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsContactShadowsOverride : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParametersOverride Parameters;
    
    UProbeLightingParamsContactShadowsOverride();
};

