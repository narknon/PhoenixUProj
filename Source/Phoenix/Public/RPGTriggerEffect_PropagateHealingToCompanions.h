#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_PropagateHealingToCompanions.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_PropagateHealingToCompanions : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Multiplier;
    
public:
    URPGTriggerEffect_PropagateHealingToCompanions();
};

