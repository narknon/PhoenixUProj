#include "BTTask_Creature_MoveTo.h"

UBTTask_Creature_MoveTo::UBTTask_Creature_MoveTo() {
    this->bUseApproachRange = true;
    this->bUseParametrizedRadius = false;
    this->bKeepPreviousSpeed = false;
    this->SpeedSetting = ECreatureMoveToSpeedSetting::SetSpeed;
    this->SpeedChange = ECreatureMovementSpeed::Walk;
    this->bKeepPreviousPathEndMode = false;
    this->PathEndModeChange = ECreaturePathEndMode::Stop;
    this->bCheckTargetHasPreferredAreaFlag = false;
    this->bCheckLocationStoppingDistancePastTarget = false;
    this->bStoreStoppingDistance = false;
    this->bReportErrorOnFailure = false;
    this->bDisableReportOnStoppingDistanceFailure = false;
}

