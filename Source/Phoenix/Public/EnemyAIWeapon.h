#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "MultiFX2Handle.h"
#include "EPhysicsMunitionHitType.h"
#include "MunitionImpactData.h"
#include "Tool.h"
#include "EEnemyAIWeaponState.h"
#include "EEnemyAIWeapon_Event.h"
#include "EEnemyWeaponEquip.h"
#include "EEnemyWeaponTypeEnum.h"
#include "EWeaponAttachmentTransformRules.h"
#include "EnemyAIWeaponEventDelegateDelegate.h"
#include "Enemy_WeaponAttackOverlapData.h"
#include "Templates/SubclassOf.h"
#include "Weapon_AnimEventDelegateDelegate.h"
#include "EnemyAIWeapon.generated.h"

class AActor;
class AMunitionType_Base;
class AMunitionType_Physics;
class APawn;
class UEnemyCorruptionData;
class UInteractionArchitectAsset;
class UMultiFX2_Base;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(Blueprintable)
class AEnemyAIWeapon : public ATool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> SuccessfulMeleeFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> SuccessfulRangedFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> BlockedMeleeFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> RecoverLocFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle RecoverFXHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyCorruptionData* AggroCorruptionSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyCorruptionData* AggroCorruptionInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AATag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AttackSelectionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AttachOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AttachRot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IAApplyEquipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IARemovedUnequipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IAApplyUnequipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer IARemovedEquipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AAApplyEquipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AARemovedUnequipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AAApplyUnequipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AARemovedEquipedTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EquipApplyTagTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreGravityWhenThrown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float throwOffsetForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float throwTargetHeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ThrowOrientRotDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ThrowRotDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ThrowMeshRotDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ProtegoRotDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoBlockSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoBounceBackSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoDeflectSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float bProtegoConstrainDirToUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DisarmRotDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DisarmMaxVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DisarmMinVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DropMaxVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DropMinVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DeathMaxVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DeathMinVel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float impactFxMinRepeatTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTerrainDestroysMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowWeaponDeflection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyWeaponOnSuccessfulPhysicsMunitionHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceLifetimeCountdownAfterRangedHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyWeaponEquip EquipMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanSwitchOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyWeaponTypeEnum StoredWeaponTypeEnum;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 EquipPriority;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 EquipWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weaponDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponAttachmentTransformRules AttachRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPowerupEligible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerupDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerupTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowSpellDeflection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAShield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnWithPhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeStored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeThrown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeDisarmed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeRecovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bJustHideForRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostThrownLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostDropLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostProtegoLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifetimeEndEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnWall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MunitionImpactType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* MunitionDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> AOE1MunitionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AOE1MunitionImpactType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AOE1MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* AOE1MunitionDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AOE1TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowOverideAttackSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsABlindManWeapon;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIWeaponEventDelegate WeaponEventDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeapon_AnimEventDelegate Weapon_AnimEventDelegate;
    
    AEnemyAIWeapon();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TrackPointsEvent();
    
    UFUNCTION(BlueprintCallable)
    void TrackPoints(const FVector& InThrowLoc, const FVector& InWieldLoc);
    
    UFUNCTION(BlueprintCallable)
    void SetState(const TEnumAsByte<EEnemyAIWeaponState::Type>& InState);
    
    UFUNCTION(BlueprintCallable)
    void RangedNotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PoweredUpStopEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PoweredUpStartEvent();
    
    UFUNCTION(BlueprintCallable)
    bool OverlapAttackCapsule_New(USceneComponent* OverlappedComponent, AActor* OtherActor, USceneComponent* OtherComponent, FHitResult SweepResult, FHitResult& OutHitResult);
    
    UFUNCTION(BlueprintCallable)
    bool OverlapAttackCapsule(AActor* InVictim, FHitResult InHitResult, FEnemy_WeaponAttackOverlapData& OutOverlapData);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionImpact(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionDestroyed(AMunitionType_Base* InMunitionInstance);
    
    UFUNCTION()
    void HandlePhysicsMunitionHit(EPhysicsMunitionHitType PhysicsMunitionHitType, FHitResult HitResult);
    
    UFUNCTION(BlueprintCallable)
    FVector GetWieldImpactNormal(const FVector& InNormal, const AActor* InHitActor);
    
    UFUNCTION(BlueprintCallable)
    FVector GetThrowImpactNormal(const FVector& InNormal, const AActor* InHitActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EEnemyAIWeaponState::Type> GetState() const;
    
    UFUNCTION(BlueprintCallable)
    AMunitionType_Physics* GetMunition();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetAttackInstigator() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceStoreWeapon();
    
    UFUNCTION(BlueprintCallable)
    void FireWeaponAOEMunitionNew(TSubclassOf<AMunitionType_Base> InMunitionActor, AActor* TargetActor, FVector InLocation, UInteractionArchitectAsset* InMunitionDataAsset, FName InMunitionImpactType, FGameplayTagContainer InMunitionTagContainer, float AOEDamage);
    
    UFUNCTION(BlueprintCallable)
    void FireWeaponAOEMunition(TSubclassOf<AMunitionType_Base> InMunitionActor, AActor* TargetActor, FVector InLocation, UInteractionArchitectAsset* InMunitionDataAsset, FName InMunitionImpactType, FGameplayTagContainer InMunitionTagContainer, float AOEDamage);
    
    UFUNCTION(BlueprintCallable)
    AMunitionType_Base* FireAtTarget(AActor* TargetPtr, APawn* WeaponOwnerPtr, float AccuracyOffset, float InDamage, float OverrideSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnableWeaponEffects();
    
    UFUNCTION(BlueprintCallable)
    void EnableTrackPoints(bool bEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EnablePhysicsSimEvent(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    AActor* DoDisarmOnOwner(FVector HitDirection, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableWeaponEffects();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastWeaponEvent(EEnemyAIWeapon_Event InEvent);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastWeapon_AnimEvent(FName InName);
    
};

