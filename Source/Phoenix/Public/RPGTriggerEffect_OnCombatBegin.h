#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_OnCombatBegin.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_OnCombatBegin : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityDuration;
    
public:
    URPGTriggerEffect_OnCombatBegin();
};

