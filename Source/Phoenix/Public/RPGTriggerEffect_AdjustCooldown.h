#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_AdjustCooldown.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_AdjustCooldown : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRelyOnItemEffectiveness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownAdjustAmount;
    
public:
    URPGTriggerEffect_AdjustCooldown();
};

