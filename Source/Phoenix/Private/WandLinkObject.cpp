#include "WandLinkObject.h"

class AActor;
class UObject;


void AWandLinkObject::WandLinkInputSuccess() {
}

void AWandLinkObject::WandLinkInputFail() {
}



bool AWandLinkObject::GetUIHidden() {
    return false;
}

AActor* AWandLinkObject::GetProtagonist() {
    return NULL;
}

EWandLinkResult AWandLinkObject::GetLethal() {
    return EWandLinkResult::LethalExplode;
}

int32 AWandLinkObject::GetCurrentStage() {
    return 0;
}

float AWandLinkObject::GetCurrentRatio() {
    return 0.0f;
}

AActor* AWandLinkObject::GetAntagonist() {
    return NULL;
}

void AWandLinkObject::Event_WandLinkSuspend(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkSuccessFX(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkStop(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkStart(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkKillBystanders(const UObject* Caller, float KillPct) {
}

void AWandLinkObject::Event_WandLinkInitialize(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkGameOver(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkForward(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkFailFX(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkDefend(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkBackward(const UObject* Caller) {
}

void AWandLinkObject::Event_WandLinkAdvanceStage(const UObject* Caller) {
}

void AWandLinkObject::Event_TeleportLocation2(const UObject* Caller) {
}

void AWandLinkObject::Event_TeleportLocation1(const UObject* Caller) {
}

AWandLinkObject::AWandLinkObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProtagonistProvider = NULL;
    this->AntagonistProvider = NULL;
    this->TeleportLocation1 = NULL;
    this->TeleportLocation2 = NULL;
    this->UIRenderScale = 1.00f;
    this->DamageToPlayerOnFailPct = 100.00f;
    this->ProtagonistMuzzleFX = NULL;
    this->ProtagonistProjectileFX = NULL;
    this->ProtagonistNudgeFX = NULL;
    this->ProtagonistSuccessFX = NULL;
    this->AntagonistMuzzleFX = NULL;
    this->AntagonistProjectileFX = NULL;
    this->AntagonistNudgeFX = NULL;
    this->AntagonistSuccessFX = NULL;
    this->BystanderBeamTime = 0.40f;
    this->ZapForce = 50000.00f;
    this->ZapMiscTimeMin = 1.00f;
    this->ZapMiscTimeMax = 3.00f;
    this->ZapTerrainChance = 50.00f;
    this->ZapTerrainZ = 1000.00f;
    this->InitialClashMunitionDataAssets = NULL;
    this->InitialClashDistance_Close = 500.00f;
    this->InitialClashForce_Close_Inner = 30000.00f;
    this->InitialClashForce_Close_Outer = 10000.00f;
    this->InitialClashDamagePct_Close = 100.00f;
    this->InitialClashDistance_Med = 1000.00f;
    this->InitialClashForce_Med_Inner = 10000.00f;
    this->InitialClashForce_Med_Outer = 1000.00f;
    this->InitialClashDamagePct_Med = 25.00f;
    this->InitialClashDistance_Far = 3000.00f;
    this->InitialClashForce_Far = 200.00f;
    this->InitialClashDamagePct_Far = 0.00f;
    this->ClashVFX = NULL;
    this->ClashStartSFXEvent = NULL;
    this->LinkLoopSFXEvent = NULL;
    this->LinkLoopEndSFXEvent = NULL;
    this->LightningBoltSFXEvent = NULL;
    this->ClashExplodeSFXEvent = NULL;
    this->LightningBoltMotionFXEvent = NULL;
    this->ProtagonistWandTipSocket = TEXT("WandSocketTip");
    this->AntagonistWandTipSocket = TEXT("WandSocketTip");
    this->ProjectileSpeed = 0.20f;
    this->ClashCameraShake = NULL;
    this->KillBystandersMunition = NULL;
    this->ProtagonistProjectile = NULL;
    this->AntagonistProjectile = NULL;
    this->ProtagonistMuzzle = NULL;
    this->AntagonistMuzzle = NULL;
    this->VFXComponent = NULL;
    this->LastCaller = NULL;
}

