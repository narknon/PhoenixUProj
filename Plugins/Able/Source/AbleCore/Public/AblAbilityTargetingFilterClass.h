#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetingFilter.h"
#include "AblAbilityTargetingFilterClass.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAbilityTargetingFilterClass : public UAblAbilityTargetingFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* m_Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Negate;
    
public:
    UAblAbilityTargetingFilterClass();
};

