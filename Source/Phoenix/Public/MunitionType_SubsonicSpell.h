#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "MunitionType_Base.h"
#include "EEnemyShieldBreaker.h"
#include "MunitionSpellInterface.h"
#include "Templates/SubclassOf.h"
#include "MunitionType_SubsonicSpell.generated.h"

class AActor;
class AActor_SubsonicProximity;
class ASpellTool;
class UAkComponent;
class UObject;
class UPrimitiveComponent;
class USphereComponent;
class UStaticMesh;
class USubsonicSpellMovementComponent;

UCLASS(Blueprintable)
class AMunitionType_SubsonicSpell : public AMunitionType_Base, public IMunitionSpellInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_explodeOnContactWithActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_explodeOnContactWithTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckForCover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_spawnStaticMeshInsteadOfTerrainFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshInsteadOfTerrainFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StaticMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_explodeWhenLifetimeExpires;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_deactivateParticlesOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_hideMeshOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_hitOnOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayVelocityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_delayedDeactivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_delayedParticleDeactivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_delayedFizzleParticleDeactivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_delayedDeathTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoPerfectSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoPerfectLoseBounce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SpawnAOECondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> m_AOE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanOppugnoAfterProtego;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OppugnoPhysicsObjectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAOEUsesSpellTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AOERadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAOEHitsVictimAgain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeDeflected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_SpawnActorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySpawnOnImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackDistanceTraveled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrackAngleToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* ProjectileMotionAkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InventoryItemToReturn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventLoudness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor_SubsonicProximity> SubsonicProximityActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USubsonicSpellMovementComponent* ProjectileMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAsyncLoadAndTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> SpawnClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SpawnClassRef;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor_SubsonicProximity* SubsonicProximityActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlapArray;
    
public:
    AMunitionType_SubsonicSpell(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetOnlyHitActor(AActor* OnlyHit, FName CollisionProfile);
    
    UFUNCTION(BlueprintCallable)
    void PlayTerrainImpact(UObject* ImpactObject, const FVector& ImpactLocation, const FVector& ImpactNormal, const FVector& ImpactVelocity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHit(const FHitResult& HitResult, bool bDestroyed, bool bHit, bool bBlocked, bool bFailed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFizzle();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFire(AActor* Target, FVector TargetLocation, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USphereComponent* GetSphereComp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USubsonicSpellMovementComponent* GetProjectileMovement() const;
    
    UFUNCTION(BlueprintCallable)
    void DisableFizzle(bool bDisable);
    
    UFUNCTION(BlueprintCallable)
    void DestroyMunition();
    
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AbortEarly();
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetPlayerShieldBreaker(bool ShieldBreaker) override PURE_VIRTUAL(SetPlayerShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    void SetEnemyShieldBreaker(EEnemyShieldBreaker ShieldBreaker) override PURE_VIRTUAL(SetEnemyShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    bool IsUnblockable(const AActor* SpellTarget) const override PURE_VIRTUAL(IsUnblockable, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerShieldBreaker() const override PURE_VIRTUAL(IsPlayerShieldBreaker, return false;);
    
    UFUNCTION(BlueprintCallable)
    EEnemyShieldBreaker IsEnemyShieldBreaker() const override PURE_VIRTUAL(IsEnemyShieldBreaker, return EEnemyShieldBreaker::None;);
    
    UFUNCTION(BlueprintCallable)
    ASpellTool* GetSpellTool() const override PURE_VIRTUAL(GetSpellTool, return NULL;);
    
};

