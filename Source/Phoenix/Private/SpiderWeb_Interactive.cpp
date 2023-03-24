#include "SpiderWeb_Interactive.h"

class AActor;
class ABiped_Character;
class UPrimitiveComponent;

void ASpiderWeb_Interactive::WebThaw() {
}

void ASpiderWeb_Interactive::WebFreeze() {
}

void ASpiderWeb_Interactive::WebBurn(FVector burnLoc) {
}

void ASpiderWeb_Interactive::WakeCompBody(UPrimitiveComponent* PrimComp) {
}

void ASpiderWeb_Interactive::UnDamp(UPrimitiveComponent* PrimComp) {
}

void ASpiderWeb_Interactive::StartSkeletalMat(ABiped_Character* SkelActor) {
}

void ASpiderWeb_Interactive::StartPhysicsMat(UPrimitiveComponent* HitComp) {
}

void ASpiderWeb_Interactive::SkeletalMat() {
}

void ASpiderWeb_Interactive::PhysicsMat() {
}

void ASpiderWeb_Interactive::PhysicsHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void ASpiderWeb_Interactive::OnWebOverlapEnd(AActor* OtherActor, UPrimitiveComponent* OtherComp) {
}

void ASpiderWeb_Interactive::OnWebOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp) {
}

void ASpiderWeb_Interactive::OnFullyCharred(bool bCharred) {
}

void ASpiderWeb_Interactive::OnFireOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASpiderWeb_Interactive::OnFireOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ASpiderWeb_Interactive::InitFireOverlap() {
}

FTransform ASpiderWeb_Interactive::GetRelativeTransform(UPrimitiveComponent* PrimComp, FVector FireLocation) {
    return FTransform{};
}

FVector ASpiderWeb_Interactive::GetCollisionScale() {
    return FVector{};
}

void ASpiderWeb_Interactive::DestroyWeb() {
}



ASpiderWeb_Interactive::ASpiderWeb_Interactive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharSpeedMode = ETargetSpeedMode::IsWalking;
    this->WebLinearDamping = 7.00f;
    this->WebAngularDamping = 7.00f;
    this->bReactiveMaterials = true;
    this->bDebugBurnSphere = false;
    this->PercentageDisableCollision = 0.50f;
    this->bFrozen = false;
    this->InMatDynamic = NULL;
    this->OutMatDynamic = NULL;
    this->PhysicsTarget = NULL;
    this->SkeletalTarget = NULL;
    this->BurnRate = 100.00f;
    this->RootComp = NULL;
    this->WebObjectState = NULL;
    this->BurnSphere = NULL;
    this->BurnDist = 0.00f;
    this->BurnDistNeeded = 0.00f;
}

