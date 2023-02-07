#include "LightGroupBoundComponentSettings.h"

FLightGroupBoundComponentSettings::FLightGroupBoundComponentSettings() {
    this->FXType = ELightOnOffFXTargetType::ParentOnly;
    this->FXMode = ELightOnOffFXTargetMode::UseParentOnOff;
    this->bInvertOnOff = false;
    this->bPropagateToChildren = false;
}

