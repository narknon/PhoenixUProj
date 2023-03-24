#include "BakedRagdollPoseActor.h"
#include "BakedRagdollPoseComponent.h"

class AActor;

void ABakedRagdollPoseActor::HandleOnActorHit(AActor* SelfActor, AActor* OtherActor, FVector ImpulseNormal, const FHitResult& HitReslt) {
}

ABakedRagdollPoseActor::ABakedRagdollPoseActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BakedPoseComponent = CreateDefaultSubobject<UBakedRagdollPoseComponent>(TEXT("BakedPoseComponent"));
    this->ActorConstrainedToUs = NULL;
}

