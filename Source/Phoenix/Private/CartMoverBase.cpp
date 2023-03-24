#include "CartMoverBase.h"

class AActor;
class UPrimitiveComponent;

void ACartMoverBase::SetMaxSpeed(const float InMaxSpeed) {
}

void ACartMoverBase::ResumeMovement() {
}

void ACartMoverBase::PauseMovement() {
}

void ACartMoverBase::OnStopBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACartMoverBase::OnStopBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACartMoverBase::OnSlowDownBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACartMoverBase::OnSlowDownBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACartMoverBase::OnDetectedEnemyDeath(AActor* EnemyAI) {
}

void ACartMoverBase::MoveAlongSpline(FCartSetup& InCartSetup, float DeltaTime) {
}

bool ACartMoverBase::IsCharacter(const AActor* ObstructingActor) const {
    return false;
}

bool ACartMoverBase::IsCartBlocking(const AActor* ObstructingActor) {
    return false;
}

bool ACartMoverBase::HasStopped() const {
    return false;
}

bool ACartMoverBase::HasReachedEndOfSpline() const {
    return false;
}

void ACartMoverBase::BeginMovement(FCartSetup& InCartSetup, bool bStartFromBeginning) {
}

ACartMoverBase::ACartMoverBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCartStopping = false;
    this->TargetSpeed = 0.00f;
    this->InterpSpeed = 0.00f;
    this->SwingLimiter = 1.00f;
    this->SwingAngle = 1.00f;
    this->TailGateTimeline = NULL;
}

