#include "AccioSpellTool.h"

class AActor;

void AAccioSpellTool::StartAccioBall() {
}

void AAccioSpellTool::PullCharacter(const FHitResult& HitResult) {
}

void AAccioSpellTool::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void AAccioSpellTool::EndAccioBall() {
}

AAccioSpellTool::AAccioSpellTool() {
    this->AccioEndThreshold = 100.00f;
    this->AccioHoverDistance = 200.00f;
    this->AccioHoverHeight = 100.00f;
    this->AccioEndSpellTime = 0.10f;
    this->SlidingDotMin = 0.50f;
    this->SlidingMinVel = 10.00f;
    this->AccioEndVelocityScale = 0.10f;
    this->FlyingBookPullVelocity = 10.00f;
    this->FlyingBookHideDistance = 5.00f;
    this->FlyingBookSlowStartScale = 2.00f;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->AccioCharacterHoverDistance = 300.00f;
    this->AccioCharacterHoverHeight = 80.00f;
    this->WingardiumSpellToolRecord = NULL;
    this->ExtendedRange = 6000.00f;
    this->AOEMunition = NULL;
    this->bSkipTriggerReaction = false;
    this->PullCharacterObjectVelocityMultiplier = 5.00f;
    this->WingardiumSpellTool = NULL;
}

