#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_ManipulateDamageInfo.generated.h"

class UModFilter_DealDamage_Base;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ManipulateDamageInfo : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionsToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UModFilter_DealDamage_Base*> DamageFilters;
    
public:
    URPGTriggerEffect_ManipulateDamageInfo();
};

