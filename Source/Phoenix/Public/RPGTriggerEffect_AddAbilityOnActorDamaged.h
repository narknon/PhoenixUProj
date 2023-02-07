#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ActorDamaged.h"
#include "RPGTriggerEffect_AddAbilityOnActorDamaged.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_AddAbilityOnActorDamaged : public URPGTriggerEffect_ActorDamaged {
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
    URPGTriggerEffect_AddAbilityOnActorDamaged();
};

