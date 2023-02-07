#include "SceneAction_PeriodicSRTrigger.h"

USceneAction_PeriodicSRTrigger::USceneAction_PeriodicSRTrigger() {
    this->MinTriggerTime = 0.00f;
    this->MaxTriggerTime = 0.00f;
    this->bTriggerImmediately = false;
    this->bStopScenerigsAtEnd = false;
}

