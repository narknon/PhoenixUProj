#include "SuperSlamFinisherComponent.h"

class AActor;
class UPrimitiveComponent;

void USuperSlamFinisherComponent::HandleSkeletalMeshComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

USuperSlamFinisherComponent::USuperSlamFinisherComponent() {
    this->SkeletalMeshComp = NULL;
    this->SuperSlamTarget = NULL;
    this->PhysicsConstraintActor = NULL;
    this->Instigator = NULL;
    this->Curve = NULL;
}

