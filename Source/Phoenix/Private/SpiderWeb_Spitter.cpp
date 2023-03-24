#include "SpiderWeb_Spitter.h"

class AActor;
class ABiped_Character;
class UPrimitiveComponent;

void ASpiderWeb_Spitter::WebThaw() {
}

void ASpiderWeb_Spitter::WebRegened_Implementation() {
}

void ASpiderWeb_Spitter::WebFreeze() {
}

void ASpiderWeb_Spitter::WebDestroyed() {
}

void ASpiderWeb_Spitter::UnDamp(UPrimitiveComponent* PrimComp) {
}

void ASpiderWeb_Spitter::StartSkeletalMat(ABiped_Character* SkelActor) {
}

void ASpiderWeb_Spitter::StartPhysicsMat(UPrimitiveComponent* HitComp) {
}

void ASpiderWeb_Spitter::SkeletalMat() {
}

FVector ASpiderWeb_Spitter::SetWebEnd(bool i_Retract, bool i_Lerp, float i_Alpha) {
    return FVector{};
}

void ASpiderWeb_Spitter::SetMeshTick(bool i_Tick) {
}

void ASpiderWeb_Spitter::SetAIBlocker(bool i_block) {
}

void ASpiderWeb_Spitter::PushBack() {
}

void ASpiderWeb_Spitter::PhysicsMat() {
}

void ASpiderWeb_Spitter::PhysicsHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void ASpiderWeb_Spitter::OnStickyOverlapEnd(AActor* OtherActor, UPrimitiveComponent* OtherComp) {
}

void ASpiderWeb_Spitter::OnStickyOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp) {
}

void ASpiderWeb_Spitter::OnPushOverlapEnd(AActor* OtherActor) {
}

void ASpiderWeb_Spitter::OnPushOverlapBegin(AActor* OtherActor) {
}

void ASpiderWeb_Spitter::InitOverlap() {
}



ASpiderWeb_Spitter::ASpiderWeb_Spitter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRegen = true;
    this->RegenTime = 8.00f;
    this->MaxWebLength = 1200.00f;
    this->bAffectPawns = true;
    this->CharSpeedMode = ETargetSpeedMode::IsWalking;
    this->WebLinearDamping = 7.00f;
    this->WebAngularDamping = 7.00f;
    this->bWebPushback = true;
    this->PushbackMaxForce = 525.00f;
    this->PushbackDistance = 50.00f;
    this->bReactiveMaterials = true;
    this->StickyTrig = NULL;
    this->PushTrig = NULL;
    this->WebMesh = NULL;
    this->WebMesh2 = NULL;
    this->WebObjectState = NULL;
    this->bFrozen = false;
    this->bBroken = false;
    this->InMatDynamic = NULL;
    this->OutMatDynamic = NULL;
    this->PhysicsTarget = NULL;
    this->SkeletalTarget = NULL;
    this->StickyTrigHalfHeight = 0.00f;
    this->PushbackExponent = 1.25f;
}

