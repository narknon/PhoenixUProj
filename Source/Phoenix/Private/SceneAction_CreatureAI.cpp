#include "SceneAction_CreatureAI.h"

USceneAction_CreatureAI::USceneAction_CreatureAI() {
    this->bSet_IdleOverrideState = false;
    this->IdleOverrideState = ECreatureIdleOverrideState::None;
    this->bSet_StationaryForNurtureInteract = false;
    this->bStationaryForNurtureInteract = true;
    this->bSet_FlyingOption = false;
    this->FlyingOption = ESceneAction_CreatureFlyingOption::StopFlying;
    this->bSet_EnablePerception = false;
    this->bEnablePerception = true;
    this->bSet_DesiredStance = false;
    this->DesiredStance = ECreatureStance::Standing;
}

