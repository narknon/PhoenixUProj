#include "RenderingCutVolume.h"

class AActor;

void ARenderingCutVolume::SetPriority(float NewPriority) {
}

void ARenderingCutVolume::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

ARenderingCutVolume::ARenderingCutVolume() {
    this->PreExposureResetValue = 0.00f;
    this->Priority = 9999.00f;
    this->bEnabled = true;
    this->bOnlyAlongPositiveXAxis = false;
}

