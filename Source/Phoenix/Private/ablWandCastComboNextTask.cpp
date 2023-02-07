#include "ablWandCastComboNextTask.h"

UablWandCastComboNextTask::UablWandCastComboNextTask() {
    this->ComboType = EWandComboType::Light;
    this->NextComboAbility = NULL;
    this->PauseComboAbility = NULL;
    this->FinisherAtFrame = 25;
    this->ResetAtFrame = 50;
    this->NextLightComboAbility = NULL;
}

