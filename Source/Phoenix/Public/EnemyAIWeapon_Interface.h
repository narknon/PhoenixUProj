#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "EEnemyBuffTypeEnum.h"
#include "EnemyAIWeapon_Interface.generated.h"

class UCapsuleComponent;
class UMeshComponent;
class USceneComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UEnemyAIWeapon_Interface : public UInterface {
    GENERATED_BODY()
};

class IEnemyAIWeapon_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool WeaponStored();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool StartWeaponSwing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SpawnStoredWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ShowWeaponStartFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InterfaceWeaponRigidBodyDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InterfaceWeaponRigidBodyActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InterfaceWeaponAcquire();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HideWeaponStopFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetSceneComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UMeshComponent* GetMeshComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCapsuleComponent* GetCapsuleComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UMeshComponent* FireWeaponAOE1();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponTriggerThrownFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponTriggerProtegoFx(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponTriggerImpactFx(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponTriggerGenericImpactFx(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponThrownPawnStabFx(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponSpawnStoredWeaponFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponMeleePawnSlashFx(const FHitResult& HitResult, const FGameplayTagContainer& InMunitionTagContainer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponMeleeAttackStartFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponImpactGlowFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponFireAOE1Fx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDisarmedFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDisarmedForRecoveryFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDestroyedFx(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDeactivateLiteFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDeactivateHeavyFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDeactivatedFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponDeactivateBuffEmitterFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponActivateLiteFx();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventWeaponActivateBuffEmitterFx(EEnemyBuffTypeEnum InBuffType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventTransientWeaponPoweredUp();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventTransientWeaponDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventTransientWeaponActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool EventTrackPoints();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventDisableRangedPawnCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool EnableShieldCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool EnablePhysicsSim();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool EnableMeleeCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool EnableCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DisableShieldCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DisablePhysicsSim();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DisableMeleeCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DisableCollision();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DeactivateWeaponThreat();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DeactivateWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ActivateWeaponThreat();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ActivateWeapon();
    
};

