#include "WingardiumBulletTimeSpellTool.h"

class AActor;
class UPrimitiveComponent;

void AWingardiumBulletTimeSpellTool::OnComponentOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AWingardiumBulletTimeSpellTool::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void AWingardiumBulletTimeSpellTool::OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}



void AWingardiumBulletTimeSpellTool::AdjustWingardiumRotation(FVector InDirection) {
}

void AWingardiumBulletTimeSpellTool::AdjustWingardiumHeight(float Adjust) {
}

void AWingardiumBulletTimeSpellTool::AdjustWingardiumDistance(float Adjust) {
}

AWingardiumBulletTimeSpellTool::AWingardiumBulletTimeSpellTool() {
    this->WingardiumComponent = NULL;
    this->MassLimit = 1000.00f;
    this->TapZVelocity = 500.00f;
    this->ImpulseScale = 1.00f;
    this->AngularImpulseScale = 10.00f;
    this->MaxImpulse = 275.00f;
    this->MaxVelocity = 1000.00f;
    this->WingardiumLinearDamping = 4.50f;
    this->WingardiumAngularDamping = 1.00f;
    this->CharacterImpulseScale = 1.00f;
    this->CharacterAngularImpulseScale = 1.00f;
    this->CharacterMaxImpulse = 275.00f;
    this->CharacterMaxVelocity = 1000.00f;
    this->CharacterLinearDamping = 4.50f;
    this->CharacterAngularDamping = 10.00f;
    this->WingardiumDistanceSpeed = 5.00f;
    this->WingardiumRotationSpeed = 2.50f;
    this->WingardiumHeightSpeed = 8.00f;
    this->WingardiumMinDistance = 250.00f;
    this->WingardiumMaxDistance = 500.00f;
    this->WingardiumMinHeight = -500.00f;
    this->WingardiumMaxHeight = 500.00f;
    this->RiseTime = 0.50f;
    this->CameraAdjustValue = 0.50f;
    this->RiseHeight = 100.00f;
    this->RiseRate = 1.00f;
    this->VelocityToTorqueScale = 1.00f;
    this->bZeroInitialOrientation = false;
    this->bRoundInitialOrientationTo90 = false;
    this->bRoundReleaseOrientationTo90 = false;
    this->bForcePositionRotation = false;
    this->HoldAtEndTime = 1.00f;
    this->DisableCharacterCollisionTime = 1.00f;
    this->DownImpulseScale = 0.50f;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->DropMinDamageDealt = -1.00f;
    this->DropMaxDamageDealt = -1.00f;
    this->DropMinDamageDealtCharacter = -1.00f;
    this->DropMaxDamageDealtCharacter = -1.00f;
    this->DropMinDamageTaken = -1.00f;
    this->DropMaxDamageTaken = -1.00f;
    this->DropMinDamageTakenCharacter = -1.00f;
    this->DropMaxDamageTakenCharacter = -1.00f;
    this->ActivePrimComponent = NULL;
}

