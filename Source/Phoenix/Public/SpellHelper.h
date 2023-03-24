#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Chaos/ChaosEngineInterface.h"
#include "CastSpellData.h"
#include "DamageInfo.h"
#include "EEnemyShieldBreaker.h"
#include "EImpactTypes.h"
#include "Templates/SubclassOf.h"
#include "SpellHelper.generated.h"

class AMunitionType_Base;
class ASpellTool;
class UAkAudioEvent;
class UInteractionArchitectAsset;
class UMultiFX2Asset;
class UParticleSystem;
class UPrimitiveComponent;
class URadialForceData;
class USceneComponent;
class USpellToolRecord;
class UStateEffectComponent;
class UToolSetComponent;
class UVelocityTrackerComponent;

UCLASS(Blueprintable)
class ASpellHelper : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UToolSetComponent* ToolSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* DummyRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<URadialForceData*> RadialForceDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCastSpellData> SpellCastArray;
    
public:
    ASpellHelper(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void UpdateSpellCast();
    
public:
    UFUNCTION(BlueprintCallable)
    static void TriggerReaction(AActor* TargetActor, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FVector SourceLocation, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static void TriggerNpcSpellResponse(AActor* InTarget, AActor* InInstigator, const FVector& Location, float Radius, bool bAlwaysUseRadius);
    
    UFUNCTION(BlueprintCallable)
    static bool SpellWillKillTarget(AActor* InTarget, AActor* InInstigator, USpellToolRecord* InSpellToolRecord, float& OutDamage);
    
    UFUNCTION(BlueprintCallable)
    static void SetVelocityTrackerMinDamage(AActor* InTarget, float MinDamageDealt, float MinDamageDealtCharacter, float MixDamageTaken, float MixDamageTakenCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void SetVelocityTrackerMaxDamage(AActor* InTarget, float MaxDamageDealt, float MaxDamageDealtCharacter, float MaxDamageTaken, float MaxDamageTakenCharacter);
    
    UFUNCTION(BlueprintCallable)
    static bool SetOnFire(AActor* Target, AActor* InInstigator, float Amount, const FVector Location, float CharacterDuration, float OverrideDamagePerSecond);
    
    UFUNCTION(BlueprintCallable)
    static bool SetFrozen(AActor* Target, AActor* InInstigator, const FVector Location);
    
    UFUNCTION(BlueprintCallable)
    static void Repair(AActor* Target, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveSpellEffect(AActor* Target, TSubclassOf<UStateEffectComponent> InRemoveEffect);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveLeviosoCountTracking(const AActor* InOwner);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveFiniteCountTracking(const AActor* InOwner);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveDeflectionComponent(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    static void PreloadSpell(USpellToolRecord* SpellToolRecord);
    
    UFUNCTION(BlueprintCallable)
    static void ObjectCanDamagePlayer(AActor* InTarget, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static bool KillTarget(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float InForce, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bSkipTakeAKnee, bool InNoReaction, bool bAlwaysKill);
    
    UFUNCTION(BlueprintCallable)
    static bool Kill(AActor* Target, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, const FHitResult& HitResult, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bSkipTakeAKnee, bool InNoReaction);
    
    UFUNCTION(BlueprintCallable)
    static void Heal(AActor* Target, float Health);
    
    UFUNCTION(BlueprintCallable)
    static ASpellTool* GetSpellTool(USpellToolRecord* InSpellToolRecord);
    
    UFUNCTION(BlueprintCallable)
    static AMunitionType_Base* FireMunition(USpellToolRecord* SpellToolRecord, FVector SourceLocation, FVector TargetLocation, AActor* InMunitionOwner, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static bool FinisherWillKillTarget(AActor* InTarget, AActor* InInstigator, float Damage);
    
    UFUNCTION(BlueprintCallable)
    static bool DoDamageTarget(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FDamageInfo& OutDamageInfo, float InDamage, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, EImpactTypes InImpactType, bool bNoReaction, bool bForceNoReaction, ASpellTool* InSpellTool);
    
    UFUNCTION(BlueprintCallable)
    static bool DoDamageOverTime(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FName InDOTType, const UMultiFX2Asset* MultiFX2, float InDamagePerSecond, float DurationInSeconds, float UpdateRate, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker);
    
    UFUNCTION(BlueprintCallable)
    static bool DoDamageLocationDirection(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FDamageInfo& OutDamageInfo, float InDamage, FVector InLocation, FVector InDirection, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, bool InNoReaction, EImpactTypes InImpactType, bool bForceNoReaction, ASpellTool* InSpellTool);
    
    UFUNCTION(BlueprintCallable)
    static void DoDamageFinisher(AActor* InTarget, AActor* InInstigator, float Damage);
    
    UFUNCTION(BlueprintCallable)
    static void DoDamageAOE(AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float InDamage, FVector InLocation, float InRadius, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bOnlyHitCharacters, bool bIgnoreSameTeam, bool bIgnoreCompanions, bool bRespectInstigatorCanHit, UAkAudioEvent* SFX, float InDuration, EImpactTypes InImpactType, ASpellTool* InSpellTool);
    
    UFUNCTION(BlueprintCallable)
    static bool DoDamage(AActor* Target, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float Amount, const FHitResult& HitResult, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, bool InNoReaction, EImpactTypes InImpactType, ASpellTool* InSpellTool);
    
    UFUNCTION(BlueprintCallable)
    static ASpellTool* CastSpellImmediate(AActor* Target, const FVector SourceLocation, USpellToolRecord* SpellToolRecord, const FVector TargetLocation, AActor* InInstigator, bool bCharged, float Duration, bool bPlayMuzzleFX, bool bPlayImpactFX, bool bHideProjectile, bool bInDebug, int32 SpellLevel, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bTriggerCastAnim, bool bOnlyHitTarget, bool bHoming, bool bRespectLock, float damageOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool CastSpell(AActor* Target, const FVector SourceLocation, USpellToolRecord* SpellToolRecord, const FVector TargetLocation, AActor* InInstigator, bool bCharged, float Duration, bool bPlayMuzzleFX, bool bPlayImpactFX, bool bHideProjectile, bool bInDebug, int32 SpellLevel, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bTriggerCastAnim, bool bOnlyHitTarget, bool bHoming, bool bRespectLock);
    
    UFUNCTION(BlueprintCallable)
    static float CalculateTimeToReachDestination(USpellToolRecord* SpellToolRecord, const FVector SourceLocation, const FVector TargetLocation);
    
    UFUNCTION(BlueprintCallable)
    static bool ApplyWetness(AActor* Target, AActor* InInstigator, float Amount, const FVector Location);
    
    UFUNCTION(BlueprintCallable)
    static void ApplySpellEffectFromPlayer(AActor* Target, USpellToolRecord* SpellToolRecord, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyRadialForceWithIgnore(FVector Location, float Impulse, const TArray<AActor*>& ActorsToIgnore, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyRadialForceToComponent(UPrimitiveComponent* InComp, FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyRadialForceToActor(AActor* InActor, FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyRadialForce(FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay);
    
    UFUNCTION(BlueprintCallable)
    static void AddVelocityTrackerTag(AActor* InTarget, FName Tag);
    
    UFUNCTION(BlueprintCallable)
    static UVelocityTrackerComponent* AddVelocityTracker(AActor* Target, AActor* InInstigator, float InLifetime, bool InRemoveWhenStopped, bool InFalling);
    
    UFUNCTION(BlueprintCallable)
    static void AddDeflectionComponent(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    static void AddCombatCursed(AActor* InTarget, AActor* InInstigator);
    
};

