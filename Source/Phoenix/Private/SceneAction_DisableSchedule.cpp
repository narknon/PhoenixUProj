#include "SceneAction_DisableSchedule.h"

USceneAction_DisableSchedule::USceneAction_DisableSchedule() {
    this->ActionOnEnter = EScheduleEnableDisable::DisableAndAbandonStations;
    this->ActionOnExit = EScheduleEnableDisable::Enable;
}

