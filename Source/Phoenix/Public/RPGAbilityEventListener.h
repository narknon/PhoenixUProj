#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RPGAbilityEventListener_Base.h"
#include "RPGAbilityEventListener.generated.h"

class AActor;
class UGameplayModComponent;
class UGameplayPropertyMod;
class URPGAbilityBase;
class URPGAbilityComponent;
class URPGTriggerEffect_Base;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGAbilityEventListener : public URPGAbilityEventListener_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerRandom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomTriggerChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<URPGAbilityBase>> Abilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameplayPropertyMod*> Mods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGTriggerEffect_Base*> TriggerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OwnerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FGuid> AbilityHandles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGameplayModComponent* ModComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URPGAbilityComponent* AbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTriggered;
    
public:
    URPGAbilityEventListener();
};

