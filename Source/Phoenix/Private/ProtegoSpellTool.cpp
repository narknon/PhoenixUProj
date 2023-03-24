#include "ProtegoSpellTool.h"

class AActor;
class AMunitionType_Base;
class UPrimitiveComponent;

bool AProtegoSpellTool::WasParryAbilityEventSent() {
    return false;
}


void AProtegoSpellTool::TurnOnProtegoEffects(bool bInShowActivateEffect, bool bInShowLoopEffect, int32 InEffectIdx) {
}

void AProtegoSpellTool::TurnOffProtegoEffects(bool bInShowDeactivateEffect, int32 InEffectIdx) {
}

void AProtegoSpellTool::StateChanged(bool bInHideShield) {
}



void AProtegoSpellTool::ShutOffProtegoTimerExpired() {
}

bool AProtegoSpellTool::ShouldShieldBeOn() {
    return false;
}

void AProtegoSpellTool::QueueParryTimerExpired() {
}

void AProtegoSpellTool::ParryWindowStackChanged(int32 NewValue) {
}


bool AProtegoSpellTool::IsDisabled() {
    return false;
}

void AProtegoSpellTool::Hit(const FHitResult& HitResult, AMunitionType_Base* MunitionInstance, AActor* HitObject, UPrimitiveComponent* OverlappedComp, bool bUnblockable, bool bOverlap, bool bMunitionImpact) {
}

void AProtegoSpellTool::HideProtego(bool bInHide) {
}

float AProtegoSpellTool::GetProtegoShieldIntensityValue() {
    return 0.0f;
}

AActor* AProtegoSpellTool::GetLastInstigator() {
    return NULL;
}

AActor* AProtegoSpellTool::GetAttackingActor() {
    return NULL;
}



bool AProtegoSpellTool::CreateLinkToAttackingActor() {
    return false;
}

AProtegoSpellTool::AProtegoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowDebug = false;
    this->bAllowTick = true;
    this->ProtegoActorClass = NULL;
    this->MinimumObjectVelocity = 0.10f;
    this->DoubleHitIgnoreTime = 0.25f;
    this->ProtegoLoopFxDelay = 1.00f;
    this->ProtegoLoopFxDelayAfterHit = 0.50f;
    this->MinActiveTimeToPlayDeactivate = 0.10f;
    this->NoDeactivateTime = 1.00f;
    this->SustainedBlastEndTime = 1.00f;
    this->PerfectBounceBackPercent = 35;
    this->PerfectTargetEnemyPercent = 50;
    this->PerfectTargetObjectPercent = 50;
    this->PerfectRandomPercent = 75;
    this->PerfectMunitionDataAsset = NULL;
    this->PerfectAOEMunitionDataAsset = NULL;
    this->PerfectMotionFX = NULL;
    this->PerfectTimeDilationCurve = NULL;
    this->PerfectDeflectDelay = 0.00f;
    this->NormalBounceBackPercent = 10;
    this->NormalTargetEnemyPercent = 20;
    this->NormalTargetObjectPercent = 20;
    this->NormalRandomPercent = 30;
    this->NormalMunitionDataAsset = NULL;
    this->NormalTimeDilationCurve = NULL;
    this->NormalDeflectDelay = 0.00f;
    this->NormalMotionFX = NULL;
    this->DeflectDistance = 1000.00f;
    this->DeflectHalfAngleXY = 45.00f;
    this->DeflectLaunchAngle = 10.00f;
    this->DeflectDelay = 0.00f;
    this->ObjectDamageRandomBlock = 200.00f;
    this->DestroyedObjectBlockForce = 200.00f;
    this->PerkIncreasedDeflectionScale = 2.00f;
    this->PerkWeakessTime = 10.00f;
    this->DeflectedMunitionMotionFX = NULL;
    this->DeflectedCharacterMotionFX = NULL;
    this->DeflectedMaxCharacterDamage = 1000.00f;
    this->DeflectedMaxObjectDamage = 1000.00f;
    this->ShieldBreakDamageScale = 1.00f;
    this->CameraShake = NULL;
    this->InnerRadius = 100.00f;
    this->OuterRadius = 1000.00f;
    this->Falloff = 1.00f;
    this->bOrientShakeTowardsEpicenter = false;
    this->ProtegoMeleeCooldown = 5.00f;
    this->AOEMunition = NULL;
    this->DisabledProtegoTime = 5.00f;
    this->InstantKillBounceChance = 0.50f;
    this->InstantKillBounceAngle = 20.00f;
    this->InstantKillBounceAngleVariance = 7.00f;
    this->InstantKillBounceDeflectionSpeedMultiplier = 2.00f;
    this->InstantKillAkEvent = NULL;
    this->OppugnoObjectSpeed = 1400.00f;
    this->OppugnoObjectMaxWobble = 0.00f;
    this->OppugnoObjectAwayRotSpeed = 10.00f;
    this->OppugnoObjectRandLeftRightAngle = 10.00f;
    this->OppugnoMinAngle = 60.00f;
    this->OppugnoMaxAngle = 80.00f;
    this->ProtegoActor = NULL;
    this->IgnoreMunition = NULL;
}

