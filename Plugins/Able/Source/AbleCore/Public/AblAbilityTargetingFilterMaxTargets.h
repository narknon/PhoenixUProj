#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetingFilter.h"
#include "AblAbilityTargetingFilterMaxTargets.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAbilityTargetingFilterMaxTargets : public UAblAbilityTargetingFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_MaxTargets;
    
public:
    UAblAbilityTargetingFilterMaxTargets();
};

