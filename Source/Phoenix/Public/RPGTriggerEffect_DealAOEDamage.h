#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_DealAOEDamage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_DealAOEDamage : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageRadius;
    
    URPGTriggerEffect_DealAOEDamage();
};

