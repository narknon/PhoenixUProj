#include "CreatureMountItemTool.h"

void ACreatureMountItemTool::SpawnAndMountCreature(bool bUseTransition, bool bInFlight) {
}

ACreatureMountItemTool::ACreatureMountItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MountHandlerClass = NULL;
    this->MountHandler = NULL;
}

