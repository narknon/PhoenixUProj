#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "ESpiderTypeEnum.h"
#include "Templates/SubclassOf.h"
#include "SpiderEggs.generated.h"

class AMunitionType_Base;
class APerceptionPointArea;
class ASpiderEggs;
class IInterface;
class UInterface;
class UAkAudioEvent;
class UAkComponent;
class UArrowComponent;
class UCognitionStimuliSourceComponent;
class UEnemyStateComponent;
class UInteractionArchitectAsset;
class ULootDropComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASpiderEggs : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SM_SpiderEggs_A_Broken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SK_SpiderEggs_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ActivationRadiusSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ProximitySphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* StealthActivationSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* LitFlames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* VFX_P_Spider_Pro_Impact_Ground_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* Ak_BP_SpiderEggs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* SpawnAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* SacFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* IncendioFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULootDropComponent* LootDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyStateComponent* EnemyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBreathing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPulsing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOnfire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasKilledByFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFrozen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsArrested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeavyBlow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFireJustStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlertProcessed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBreathStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> mActorsInRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mActivationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mStealthActivationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBurstTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBurstDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASpiderEggs*> mNearbyEggsForAlert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mNearEggAlertRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mNearEggAlertTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mNearEggAlertDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASpiderEggs*> mProximityEggs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mProximityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mForceBurstTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mForceBurstDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle mForceBurstHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D mSpiderSpawnRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mExplodeDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mExplodeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDamageDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector mInitialScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnSpidersOnExplode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnWhenHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreTriggerSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpiderTypeEnum mSpidersToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSpawnAngleSpread;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mSpawnLandDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnLootOnExplode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mLootChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform mSpawnTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFireLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mFireDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mBreathingAnimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mPulsingAnimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mAsyncLoadRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> mST_Woodlouse_Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> mST_Venomous_Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> mST_Luminous_Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAkAudioEvent> mAkEvent_ExplodeRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> mNiagara_HeavyFireBurstEffectRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> mNiagara_FirePopEffectRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> mNiagara_FrozenBurstEffectRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> mNiagara_DamagedEffectRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> mFireDamageMunitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInterface> mExplodeIgnoreInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> mExplodeMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APerceptionPointArea*> StayInVolumeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanRemoveStayInVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StayInRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StayInVolumeTeleportTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStayInVolumeOffNavTeleport;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* mAkEvent_Explode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* mNiagara_HeavyFireBurstEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* mNiagara_FirePopEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* mNiagara_FrozenBurstEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* mNiagara_DamagedEffect;
    
public:
    ASpiderEggs(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopPulse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartPulse();
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd_StealthActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd_ProximitySphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd_ActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin_StealthActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin_ProximitySphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin_ActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBurst();
    
    UFUNCTION(BlueprintCallable)
    void _UpdateObjectState();
    
    UFUNCTION(BlueprintCallable)
    void _StopPulse();
    
    UFUNCTION(BlueprintCallable)
    void _StopMotion();
    
    UFUNCTION(BlueprintCallable)
    void _StopForceBurstDelay();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void _StopFireLight();
    
    UFUNCTION(BlueprintCallable)
    void _StopFire();
    
    UFUNCTION(BlueprintCallable)
    void _StopExplodeDelay();
    
    UFUNCTION(BlueprintCallable)
    void _StopBreathing();
    
    UFUNCTION(BlueprintCallable)
    void _StopAlertDelay();
    
    UFUNCTION(BlueprintCallable)
    void _StartTimerDelays();
    
    UFUNCTION(BlueprintCallable)
    void _StartPulse();
    
    UFUNCTION(BlueprintCallable)
    void _StartMotion();
    
    UFUNCTION(BlueprintCallable)
    void _StartForceBurstDelay();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void _StartFireLight();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void _StartExplode();
    
    UFUNCTION(BlueprintCallable)
    void _StartBurst();
    
    UFUNCTION(BlueprintCallable)
    void _StartBreathing();
    
    UFUNCTION(BlueprintCallable)
    void _SpawnLoot();
    
    UFUNCTION(BlueprintCallable)
    void _SpawnEnemies();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void _SetupParamsForSpawnType();
    
    UFUNCTION(BlueprintCallable)
    void _ResumePulse();
    
    UFUNCTION(BlueprintCallable)
    void _ResumeMotion();
    
    UFUNCTION(BlueprintCallable)
    void _ResumeBreathing();
    
    UFUNCTION(BlueprintCallable)
    bool _RemoveActorInRadius(AActor* InActor, bool RemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void _PropagateFire();
    
    UFUNCTION(BlueprintCallable)
    void _PrintDebug(const FString& Name, const float Value);
    
    UFUNCTION(BlueprintCallable)
    void _PlayExplodeEffects();
    
    UFUNCTION(BlueprintCallable)
    void _PlayDamagedEffects(const float InDamage);
    
    UFUNCTION(BlueprintCallable)
    void _PausePulse();
    
    UFUNCTION(BlueprintCallable)
    void _PauseMotion();
    
    UFUNCTION(BlueprintCallable)
    void _PauseBreathing();
    
    UFUNCTION(BlueprintCallable)
    void _LightFire();
    
    UFUNCTION(BlueprintCallable)
    bool _IsPausedBySpell();
    
    UFUNCTION(BlueprintCallable)
    void _HideEggSacMesh();
    
    UFUNCTION(BlueprintCallable)
    void _HideBaseMesh();
    
    UFUNCTION(BlueprintCallable)
    void _HeavyBlowExplode();
    
    UFUNCTION(BlueprintCallable)
    bool _HasActorsInRadius();
    
    UFUNCTION(BlueprintCallable)
    void _ForceBurstStart();
    
    UFUNCTION(BlueprintCallable)
    void _ForceBurst();
    
    UFUNCTION(BlueprintCallable)
    void _FireTick();
    
    UFUNCTION(BlueprintCallable)
    void _Fire();
    
    UFUNCTION(BlueprintCallable)
    FTransform _FindValidEnemySpawn();
    
    UFUNCTION(BlueprintCallable)
    void _Explode();
    
    UFUNCTION(BlueprintCallable)
    void _DoDamageOnExplode();
    
    UFUNCTION(BlueprintCallable)
    void _DoDamageFire();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void _CancelExplode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void _CallDispatcher();
    
    UFUNCTION(BlueprintCallable)
    void _AlertNearby();
    
    UFUNCTION(BlueprintCallable)
    bool _AddActorInRadius(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void _ActivateObject();
    
};

