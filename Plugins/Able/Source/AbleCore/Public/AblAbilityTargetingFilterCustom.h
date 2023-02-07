#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetingFilter.h"
#include "AblAbilityTargetingFilterCustom.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAbilityTargetingFilterCustom : public UAblAbilityTargetingFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_UseAsync;
    
public:
    UAblAbilityTargetingFilterCustom();
};

