#include "SpellHelper.h"
#include "Components/SceneComponent.h"
#include "ToolSetComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AMunitionType_Base;
class ASpellTool;
class UAkAudioEvent;
class UInteractionArchitectAsset;
class UMultiFX2Asset;
class UParticleSystem;
class UPrimitiveComponent;
class USpellToolRecord;
class UStateEffectComponent;
class UVelocityTrackerComponent;

void ASpellHelper::UpdateSpellCast() {
}

void ASpellHelper::TriggerReaction(AActor* TargetActor, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FVector SourceLocation, AActor* InInstigator) {
}

void ASpellHelper::TriggerNpcSpellResponse(AActor* InTarget, AActor* InInstigator, const FVector& Location, float Radius, bool bAlwaysUseRadius) {
}

bool ASpellHelper::SpellWillKillTarget(AActor* InTarget, AActor* InInstigator, USpellToolRecord* InSpellToolRecord, float& OutDamage) {
    return false;
}

void ASpellHelper::SetVelocityTrackerMinDamage(AActor* InTarget, float MinDamageDealt, float MinDamageDealtCharacter, float MixDamageTaken, float MixDamageTakenCharacter) {
}

void ASpellHelper::SetVelocityTrackerMaxDamage(AActor* InTarget, float MaxDamageDealt, float MaxDamageDealtCharacter, float MaxDamageTaken, float MaxDamageTakenCharacter) {
}

bool ASpellHelper::SetOnFire(AActor* Target, AActor* InInstigator, float Amount, const FVector Location, float CharacterDuration, float OverrideDamagePerSecond) {
    return false;
}

bool ASpellHelper::SetFrozen(AActor* Target, AActor* InInstigator, const FVector Location) {
    return false;
}

void ASpellHelper::Repair(AActor* Target, AActor* InInstigator) {
}

void ASpellHelper::RemoveSpellEffect(AActor* Target, TSubclassOf<UStateEffectComponent> InRemoveEffect) {
}

void ASpellHelper::RemoveLeviosoCountTracking(const AActor* InOwner) {
}

void ASpellHelper::RemoveFiniteCountTracking(const AActor* InOwner) {
}

void ASpellHelper::RemoveDeflectionComponent(AActor* InTarget) {
}

void ASpellHelper::PreloadSpell(USpellToolRecord* SpellToolRecord) {
}

void ASpellHelper::ObjectCanDamagePlayer(AActor* InTarget, AActor* InInstigator) {
}

bool ASpellHelper::KillTarget(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float InForce, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bSkipTakeAKnee, bool InNoReaction, bool bAlwaysKill) {
    return false;
}

bool ASpellHelper::Kill(AActor* Target, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, const FHitResult& HitResult, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bSkipTakeAKnee, bool InNoReaction) {
    return false;
}

void ASpellHelper::Heal(AActor* Target, float Health) {
}

ASpellTool* ASpellHelper::GetSpellTool(USpellToolRecord* InSpellToolRecord) {
    return NULL;
}

AMunitionType_Base* ASpellHelper::FireMunition(USpellToolRecord* SpellToolRecord, FVector SourceLocation, FVector TargetLocation, AActor* InMunitionOwner, AActor* InInstigator) {
    return NULL;
}

bool ASpellHelper::FinisherWillKillTarget(AActor* InTarget, AActor* InInstigator, float Damage) {
    return false;
}

bool ASpellHelper::DoDamageTarget(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FDamageInfo& OutDamageInfo, float InDamage, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, EImpactTypes InImpactType, bool bNoReaction, bool bForceNoReaction, ASpellTool* InSpellTool) {
    return false;
}

bool ASpellHelper::DoDamageOverTime(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FName InDOTType, const UMultiFX2Asset* MultiFX2, float InDamagePerSecond, float DurationInSeconds, float UpdateRate, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker) {
    return false;
}

bool ASpellHelper::DoDamageLocationDirection(AActor* InTarget, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, FDamageInfo& OutDamageInfo, float InDamage, FVector InLocation, FVector InDirection, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, bool InNoReaction, EImpactTypes InImpactType, bool bForceNoReaction, ASpellTool* InSpellTool) {
    return false;
}

void ASpellHelper::DoDamageFinisher(AActor* InTarget, AActor* InInstigator, float Damage) {
}

void ASpellHelper::DoDamageAOE(AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float InDamage, FVector InLocation, float InRadius, float InForce, bool bSendImpact, bool bIgnoreDamageThreshold, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bOnlyHitCharacters, bool bIgnoreSameTeam, bool bIgnoreCompanions, bool bRespectInstigatorCanHit, UAkAudioEvent* SFX, float InDuration, EImpactTypes InImpactType, ASpellTool* InSpellTool) {
}

bool ASpellHelper::DoDamage(AActor* Target, AActor* InInstigator, FGameplayTagContainer InMunitionTagContainer, TArray<UInteractionArchitectAsset*> InMunitionDataAssets, float Amount, const FHitResult& HitResult, bool bSendImpact, bool bIgnoreDamageThreshold, float InDestructionForce, float InRadialDestructionForce, UParticleSystem* InDestroyPieceVFX, float InDestroyPieceVFXRadius, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, UAkAudioEvent* SFX, float InDuration, bool InNoReaction, EImpactTypes InImpactType, ASpellTool* InSpellTool) {
    return false;
}

ASpellTool* ASpellHelper::CastSpellImmediate(AActor* Target, const FVector SourceLocation, USpellToolRecord* SpellToolRecord, const FVector TargetLocation, AActor* InInstigator, bool bCharged, float Duration, bool bPlayMuzzleFX, bool bPlayImpactFX, bool bHideProjectile, bool bInDebug, int32 SpellLevel, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bTriggerCastAnim, bool bOnlyHitTarget, bool bHoming, bool bRespectLock, float damageOverride) {
    return NULL;
}

bool ASpellHelper::CastSpell(AActor* Target, const FVector SourceLocation, USpellToolRecord* SpellToolRecord, const FVector TargetLocation, AActor* InInstigator, bool bCharged, float Duration, bool bPlayMuzzleFX, bool bPlayImpactFX, bool bHideProjectile, bool bInDebug, int32 SpellLevel, bool bPlayerShieldBreaker, EEnemyShieldBreaker EnemyShieldBreaker, bool bTriggerCastAnim, bool bOnlyHitTarget, bool bHoming, bool bRespectLock) {
    return false;
}

float ASpellHelper::CalculateTimeToReachDestination(USpellToolRecord* SpellToolRecord, const FVector SourceLocation, const FVector TargetLocation) {
    return 0.0f;
}

bool ASpellHelper::ApplyWetness(AActor* Target, AActor* InInstigator, float Amount, const FVector Location) {
    return false;
}

void ASpellHelper::ApplySpellEffectFromPlayer(AActor* Target, USpellToolRecord* SpellToolRecord, float Duration) {
}

void ASpellHelper::ApplyRadialForceWithIgnore(FVector Location, float Impulse, const TArray<AActor*>& ActorsToIgnore, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay) {
}

void ASpellHelper::ApplyRadialForceToComponent(UPrimitiveComponent* InComp, FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay) {
}

void ASpellHelper::ApplyRadialForceToActor(AActor* InActor, FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay) {
}

void ASpellHelper::ApplyRadialForce(FVector Location, float Impulse, float MassScaledImpulse, float Radius, TEnumAsByte<ERadialImpulseFalloff> Falloff, bool bVelChange, float Delay) {
}

void ASpellHelper::AddVelocityTrackerTag(AActor* InTarget, FName Tag) {
}

UVelocityTrackerComponent* ASpellHelper::AddVelocityTracker(AActor* Target, AActor* InInstigator, float InLifetime, bool InRemoveWhenStopped, bool InFalling) {
    return NULL;
}

void ASpellHelper::AddDeflectionComponent(AActor* InTarget) {
}

void ASpellHelper::AddCombatCursed(AActor* InTarget, AActor* InInstigator) {
}

ASpellHelper::ASpellHelper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("ToolSetComponent"));
    this->DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

