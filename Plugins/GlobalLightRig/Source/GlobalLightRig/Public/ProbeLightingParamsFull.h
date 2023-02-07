#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingParameters.h"
#include "ProbeLightingParams.h"
#include "ProbeLightingParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParamsFull : public UProbeLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingParameters Parameters;
    
    UProbeLightingParamsFull();
};

