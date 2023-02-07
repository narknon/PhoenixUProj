#include "ablAnimEventTask.h"

UablAnimEventTask::UablAnimEventTask() {
    this->Event = EEnemy_AbilityEvent::None;
    this->EndEvent = EEnemy_AbilityEvent::None;
    this->MinIntervalSeconds = 0.00f;
    this->bMustPassAllConditions = true;
}

