#include "AIPerformTaskTrigger.h"

class AActor;
class UPrimitiveComponent;

void UAIPerformTaskTrigger::OnWaitTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

UAIPerformTaskTrigger::UAIPerformTaskTrigger() {
    this->WaitTrigger = NULL;
    this->bOrientToPlayer = true;
}

