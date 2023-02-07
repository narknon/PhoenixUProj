#include "Distance_TASChoice.h"

UDistance_TASChoice::UDistance_TASChoice() {
    this->TargetCriteriaNotMetState = ENPC_TurnAssistState::PathLoc;
    this->StartMaxAngleToDest = 90.00f;
    this->ContinueMaxAngleToDest = 90.00f;
    this->StartMinDistToDest = 600.00f;
    this->ContinueMinDistToDest = 600.00f;
    this->StartMinDistToTarget = 800.00f;
    this->ContinueMinDistToTarget = 800.00f;
    this->StartAngleOverrideMinDistToTarget = 2200.00f;
    this->ContinueAngleOverrideMinDistToTarget = 1800.00f;
}

