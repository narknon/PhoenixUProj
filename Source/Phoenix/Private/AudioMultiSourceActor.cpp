#include "AudioMultiSourceActor.h"

AAudioMultiSourceActor::AAudioMultiSourceActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DensityScale = 1.00f;
    this->RandomSeed = 0;
    this->ClumpingFactor = 200.00f;
    this->bManuallyModifiedSamplePoints = false;
}

