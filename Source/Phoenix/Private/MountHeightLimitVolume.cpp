#include "MountHeightLimitVolume.h"

class AActor;
class UPrimitiveComponent;

void AMountHeightLimitVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AMountHeightLimitVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AMountHeightLimitVolume::AMountHeightLimitVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FlyHeightOverride = 0.00f;
}

