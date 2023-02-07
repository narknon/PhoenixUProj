#include "AblNPC_PhysicalReactionTask.h"

UAblNPC_PhysicalReactionTask::UAblNPC_PhysicalReactionTask() {
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
    this->CcdTime = -1.00f;
}

