#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ProtegoReflectAttack.h"
#include "RPGTriggerEffect_ProtegoTriggerAbility.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ProtegoTriggerAbility : public URPGTriggerEffect_ProtegoReflectAttack {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<URPGAbilityBase> RPGAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseIngameSimulationTime;
    
public:
    URPGTriggerEffect_ProtegoTriggerAbility();
};

