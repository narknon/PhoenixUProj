#pragma once
#include "CoreMinimal.h"
#include "ProbeContactShadowsParameters.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsContactShadows.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsContactShadows : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParameters Parameters;
    
    UProbeLightingParamsContactShadows();
};

