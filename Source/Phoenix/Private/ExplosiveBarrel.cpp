#include "ExplosiveBarrel.h"

class AActor;

bool AExplosiveBarrel::SphereOverlap(TArray<AActor*>& OutActors) {
    return false;
}

void AExplosiveBarrel::SortAffectedActors(TArray<AActor*>& OutActors) {
}

void AExplosiveBarrel::KillBarrel() {
}

void AExplosiveBarrel::HitByBombarda() {
}

float AExplosiveBarrel::GetExplosionVFXScale() const {
    return 0.0f;
}

void AExplosiveBarrel::ExplodeStart_Implementation() {
}

void AExplosiveBarrel::ExplodeEnd() {
}

bool AExplosiveBarrel::ExplodeDamage(AActor* DamageActor) {
    return false;
}


AExplosiveBarrel::AExplosiveBarrel() {
    this->BarrelMesh = NULL;
    this->bSimulatePhysics = true;
    this->ExplosionTimer = 5.00f;
    this->ExplodeDelay = 0.08f;
    this->ExplosionRadius = 600.00f;
    this->Falloff = RIF_Constant;
    this->ImpulseStrength = 100000.00f;
    this->AdditionalRadialForce = 300000.00f;
    this->ExplosionVFXScale = 2.00f;
    this->ExplosionDamage_Objects = 250.00f;
    this->ExplosionDamage_Pawns = 250.00f;
    this->PropagateFireChance = 0.40f;
    this->FireDamage = 20.00f;
    this->TraceVisibility = EDrawDebugTrace::None;
    this->BombardaExplosionRadius = 600.00f;
    this->BombardaImpulseStrength = 100000.00f;
    this->BombardaAdditionalRadialForce = 300000.00f;
    this->BombardaExplosionVFXScale = 2.00f;
    this->BombardaExplosionDamage_Objects = 250.00f;
    this->BombardaExplosionDamage_Pawns = 250.00f;
    this->BarrelInstigator = NULL;
    this->DamageDataAsset = NULL;
}

