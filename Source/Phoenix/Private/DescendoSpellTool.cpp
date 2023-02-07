#include "DescendoSpellTool.h"

class AActor;

void ADescendoSpellTool::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

ADescendoSpellTool::ADescendoSpellTool() {
    this->PushToGroundDelay = 0.25f;
    this->GroundDamage = 50.00f;
    this->MinDamageDealt = -1.00f;
    this->MaxDamageDealt = -1.00f;
    this->MinDamageDealtCharacter = -1.00f;
    this->MaxDamageDealtCharacter = -1.00f;
    this->MinDamageTaken = -1.00f;
    this->MaxDamageTaken = -1.00f;
    this->MinDamageTakenCharacter = -1.00f;
    this->MaxDamageTakenCharacter = -1.00f;
    this->MinimumTorque = 400.00f;
    this->ApplyTorqueDelay = 0.01f;
    this->BasePhysicsImpulse = 0.00f;
    this->MassScaledPhysicsImpulse = 2000.00f;
    this->MaxVelocity = 2500.00f;
    this->NonMovableDamage = 0.00f;
    this->NonMovableAdditionalForce = 1000.00f;
    this->AOEMunition = NULL;
}

