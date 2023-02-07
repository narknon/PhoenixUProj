#include "AblSpiderFallTumbleTask.h"

class AActor;

void UAblSpiderFallTumbleTask::HandleBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

UAblSpiderFallTumbleTask::UAblSpiderFallTumbleTask() {
    this->ParentClass = NULL;
    this->ReactionAbility = NULL;
    this->ProtegoReactionAbility = NULL;
    this->SplatAbility = NULL;
    this->BranchAtFloorHeight = 50.00f;
    this->MaxSplatSpeed = 250.00f;
    this->RandRadianAngle = 0.35f;
    this->FloorImpactDamping = 0.35f;
    this->FloorImpactDampingVariance = 0.05f;
    this->MinSpeed = 100.00f;
    this->MaxSpeed = 1000.00f;
    this->ProtegoParticleSystem = NULL;
}

