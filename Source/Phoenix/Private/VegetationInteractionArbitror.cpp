#include "VegetationInteractionArbitror.h"

AVegetationInteractionArbitror::AVegetationInteractionArbitror(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisplacementCameraDistanceCutoff = 3500.00f;
    this->bSuspend = false;
}

