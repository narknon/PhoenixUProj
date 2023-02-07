#include "AISenseSpecificDetails.h"

UAISenseSpecificDetails::UAISenseSpecificDetails() {
    this->TargetPointClass = NULL;
    this->FarDistanceOverride = -1.00f;
    this->bPositionCallOutsOverPerceiver = false;
    this->bPerceiverHeadtracksToTarget = true;
    this->bAllowStencil = true;
    this->bCalloutAboveCollision = true;
}

