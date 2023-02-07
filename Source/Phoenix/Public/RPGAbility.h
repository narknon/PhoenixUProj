#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGAbilityBase.h"
#include "RPGTimeTriggers.h"
#include "RPGAbility.generated.h"

class UGameplayPropertyMod;
class URPGAbilityEventListener_Base;
class URPGCondition;
class URPGTriggerEffect_Base;

UCLASS(Blueprintable)
class URPGAbility : public URPGAbilityBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameplayPropertyMod*> Mods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AbilityTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGAbilityEventListener_Base*> EventReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGTriggerEffect_Base*> TriggerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGTriggerEffect_Base*> BeginAbilityTriggerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGTriggerEffect_Base*> EndAbilityTriggerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRPGTimeTriggers> TimeTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGCondition*> EndConditions;
    
public:
    URPGAbility();
};

