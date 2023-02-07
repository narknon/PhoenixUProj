#include "TimeRigInterval.h"

class UTimeRigElementState;
class UTimeRigInstanceContext;

void UTimeRigInterval::OnStartChanged(FTimeRigCoordinate Previous, FTimeRigCoordinate Current, UTimeRigInstanceContext* Context, UTimeRigElementState* State) {
}

void UTimeRigInterval::OnFinishChanged(FTimeRigCoordinate Previous, FTimeRigCoordinate Current, UTimeRigInstanceContext* Context, UTimeRigElementState* State) {
}

UTimeRigInterval::UTimeRigInterval() {
    this->SortOrder = 0.00f;
    this->UsePostActorTick = false;
}

