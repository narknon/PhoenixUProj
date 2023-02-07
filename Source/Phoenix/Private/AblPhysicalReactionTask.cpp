#include "AblPhysicalReactionTask.h"

UAblPhysicalReactionTask::UAblPhysicalReactionTask() {
    this->Action = EPhysicalReactionTaskAction::StartImpactReaction;
    this->ReactionStrength = EImpactReactionStrength::Hitch;
    this->bBlendBackOnTaskEnd = false;
    this->SetPoseDrivingMode = ERagdollDrivingSetting::KeepCurrent;
    this->PoseDrivingMode = ERagdollPoseDrivingMode::Strong;
    this->PoseDrivingBlendDuration = 0.50f;
    this->bSetCenterOfMassDrivingModes = false;
    this->LocationDrivingMode = ERagdollCOMLocationDrivingMode::NoDriving;
    this->RotationDrivingMode = ERagdollCOMRotationDrivingMode::NoDriving;
    this->bEnableCcd = false;
    this->CcdTime = 2.00f;
}

