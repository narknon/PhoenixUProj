#include "PickupTool.h"





void APickupTool::DeactivateTool_Implementation() {
}

APickupTool::APickupTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AccioCatchable = false;
}

