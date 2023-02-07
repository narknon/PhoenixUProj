#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleBlendDomainPreComputed.h"
#include "WorldFXRuleBlendDomainThreshold.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainThreshold : public UWorldFXRuleBlendDomainPreComputed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UWorldFXRuleBlendDomainThreshold();
};

