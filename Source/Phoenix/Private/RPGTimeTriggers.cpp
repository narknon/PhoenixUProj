#include "RPGTimeTriggers.h"

FRPGTimeTriggers::FRPGTimeTriggers() {
    this->bUseRatioOfLifetime = false;
    this->Unit = Weeks;
    this->StartTime = 0.00f;
    this->StopTime = 0.00f;
    this->RetriggerBehaviour = Restart;
    this->TriggerEffect = NULL;
    this->bIsActive = false;
    this->bWasActive = false;
    this->bUseIngameSimulationTime = false;
    this->bRepeating = false;
    this->LoopPauseTime = 0.00f;
}

