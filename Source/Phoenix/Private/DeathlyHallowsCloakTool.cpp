#include "DeathlyHallowsCloakTool.h"

class AActor;



void ADeathlyHallowsCloakTool::CasterHealthZero(AActor* InActor) {
}

ADeathlyHallowsCloakTool::ADeathlyHallowsCloakTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisillusionmentMat = NULL;
    this->bSlowWalk = true;
}

