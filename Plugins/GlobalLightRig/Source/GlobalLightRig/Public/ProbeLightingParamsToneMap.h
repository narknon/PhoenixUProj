#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingToneMapParameters.h"
#include "ProbeLightingParamsToneMap.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsToneMap : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParameters Parameters;
    
    UProbeLightingParamsToneMap();
};

