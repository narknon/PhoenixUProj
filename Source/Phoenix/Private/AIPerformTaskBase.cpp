#include "AIPerformTaskBase.h"

class AActor;
class UScheduledEntity;

void UAIPerformTaskBase::OnPerformTaskExecutionCompleteImp(UScheduledEntity* ScheduledEntity, int32 ActivityTypeBits) {
}

void UAIPerformTaskBase::OnFleshLoadComplete(AActor* FleshActor) {
}

UAIPerformTaskBase::UAIPerformTaskBase() {
    this->ParallelSceneRigActor = NULL;
    this->bSkipThisTask = false;
    this->bShouldWaitToFinish = true;
    this->bTrackPlayer = false;
    this->HeadTrackingTargetActor = NULL;
    this->PerformTaskContainer = NULL;
}

