#include "ThrowableInventoryItemTool.h"

float AThrowableInventoryItemTool::GetMaxDistance() {
    return 0.0f;
}

AThrowableInventoryItemTool::AThrowableInventoryItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxDistance = 2000.00f;
}

