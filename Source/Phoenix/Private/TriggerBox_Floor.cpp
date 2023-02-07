#include "TriggerBox_Floor.h"

class AActor;
class UPrimitiveComponent;

void ATriggerBox_Floor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ATriggerBox_Floor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ATriggerBox_Floor::ATriggerBox_Floor() {
}

