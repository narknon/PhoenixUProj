#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableProbeLighting.generated.h"

class UProbeLightingParams;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableProbeLighting : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProbeLightingParams* ProbeLightingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType OverrideSource;
    
    UGlobalLightingBlendableProbeLighting();
};

