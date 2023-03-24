#include "PuzzleTarget.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

class AActor;
class UPrimitiveComponent;

void APuzzleTarget::StartMove(AActor* OtherActor) {
}

void APuzzleTarget::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void APuzzleTarget::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

FVector APuzzleTarget::GetNewVelocity(UPrimitiveComponent* PrimComp) {
    return FVector{};
}

APuzzleTarget::APuzzleTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VolumeComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
    this->TargetComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Target"));
    this->bCanComplete = true;
    this->NumActorsToComplete = 0;
    this->MoveSpeed = 3.00f;
    this->RotationSpeed = 7.00f;
    this->MarginOfError = 10.00f;
    this->bStopMovingWhenFinished = false;
    this->bSnapToTarget = false;
    this->bRotateToTarget = true;
    this->bCancelMomentum = true;
    this->bCancelSpellsOnTargetReached = false;
    this->bOneAtATime = false;
    this->bMoving = false;
    this->bDoOnce = false;
}

