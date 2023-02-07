#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleBlendDomainPreComputed.h"
#include "WorldFXRuleBlendDomainRange.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainRange : public UWorldFXRuleBlendDomainPreComputed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxThreshold;
    
    UWorldFXRuleBlendDomainRange();
};

