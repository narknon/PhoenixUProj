#include "SceneAction_PlayerPerception.h"

USceneAction_PlayerPerception::USceneAction_PlayerPerception() {
    this->InteractTargeting = EPlayerPerceptionEnableDisable::Ignore;
    this->AutoTargeting = EPlayerPerceptionEnableDisable::Ignore;
    this->OppugnoTargeting = EPlayerPerceptionEnableDisable::Ignore;
    this->SpecialAutoTarget = NULL;
}

