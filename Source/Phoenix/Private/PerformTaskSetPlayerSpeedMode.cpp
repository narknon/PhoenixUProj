#include "PerformTaskSetPlayerSpeedMode.h"

UPerformTaskSetPlayerSpeedMode::UPerformTaskSetPlayerSpeedMode() {
    this->SpeedMode = ETargetSpeedMode::None;
    this->SpeedModifier = ETargetSpeedMode::None;
    this->bShouldRevertToDefault = false;
    this->changePlayerSpeedRadius = 0.00f;
    this->revertRadius = 0.00f;
}

