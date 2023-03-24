#include "AkSpotReflector.h"

AAkSpotReflector::AAkSpotReflector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EarlyReflectionAuxBus = NULL;
    this->AcousticTexture = NULL;
    this->DistanceScalingFactor = 2.00f;
    this->Level = 1.00f;
}

