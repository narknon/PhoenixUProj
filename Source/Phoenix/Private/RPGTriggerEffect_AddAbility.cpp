#include "RPGTriggerEffect_AddAbility.h"

URPGTriggerEffect_AddAbility::URPGTriggerEffect_AddAbility() {
    this->DurationUnit = Seconds;
    this->Duration = 0.00f;
    this->bUseIngameSimulationTime = true;
    this->bResetOnDayEnd = false;
}

