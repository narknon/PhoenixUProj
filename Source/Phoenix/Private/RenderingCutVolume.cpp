#include "RenderingCutVolume.h"

class AActor;

void ARenderingCutVolume::SetPriority(float NewPriority) {
}

void ARenderingCutVolume::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

ARenderingCutVolume::ARenderingCutVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreExposureResetValue = 0.00f;
    this->Priority = 9999.00f;
    this->bEnabled = true;
    this->bOnlyAlongPositiveXAxis = false;
}

