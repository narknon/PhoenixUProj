#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "CombativePlantComponent.generated.h"

class AActor;
class AInventoryObject;
class UAblAbility;
class UAkAudioEvent;
class UCognitionStimuliSourceComponent;
class UNiagaraSystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCombativePlantComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDealDamage, AActor*, AttackTarget, float, Damage, const FHitResult&, Hit);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCinematicChange);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCabbagePerkActivate);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBePickedUp;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDealDamage OnDealDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCabbagePerkActivate OnCabbagePerkActivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCinematicChange OnCinematicStartedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCinematicChange OnCinematicFinishedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* RecallAudioEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* RecallVisualEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> RespondToPlayerAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PerkFinalAttackContainer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwitchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerIsInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldEmitPerceptionEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionEventTimePeriod;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
public:
    UCombativePlantComponent();
    UFUNCTION(BlueprintCallable)
    void PickedUp(AInventoryObject* InInventoryObject, int32 InCount);
    
    UFUNCTION(BlueprintCallable)
    void OnRecall();
    
    UFUNCTION(BlueprintCallable)
    void GenerateFocus(AActor* InActor, float InDamage, const FHitResult& InHit);
    
private:
    UFUNCTION(BlueprintCallable)
    void EmitPerceptionEvent();
    
    UFUNCTION(BlueprintCallable)
    void DisablePickup();
    
public:
    UFUNCTION(BlueprintCallable)
    bool AddObjectToInventory(const AActor* InInventoryHolder);
    
};

