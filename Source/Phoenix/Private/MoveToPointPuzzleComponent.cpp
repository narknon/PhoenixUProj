#include "MoveToPointPuzzleComponent.h"

class AActor;
class UPrimitiveComponent;

void UMoveToPointPuzzleComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo) {
}

bool UMoveToPointPuzzleComponent::Move(FVector Direction, float Speed) {
    return false;
}

UMoveToPointPuzzleComponent::UMoveToPointPuzzleComponent() {
    this->TargetThreshold = 10.00f;
    this->Friction = 0.00f;
    this->BounceFriction = 0.70f;
    this->CollisionSpeedAdjustment = 0.75f;
    this->TargetOrientation = ETargetOrientation::TargetAxis;
    this->bMustMatchFinalOrientation = false;
    this->FinalOrientation = 0;
}

