#include "NoDismountZoneVolume.h"

class AActor;
class UPrimitiveComponent;

void ANoDismountZoneVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ANoDismountZoneVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ANoDismountZoneVolume::ANoDismountZoneVolume() {
}

