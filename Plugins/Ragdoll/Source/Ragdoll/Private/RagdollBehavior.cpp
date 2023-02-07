#include "RagdollBehavior.h"

URagdollBehavior::URagdollBehavior() {
    this->AllowGetup = false;
    this->COMLocationDriveMode = ERagdollCOMLocationDrivingMode::NoDriving;
    this->COMRotationDriveMode = ERagdollCOMRotationDrivingMode::NoDriving;
    this->DriveAnimationMode = ERagdollDriveAnimEnum::DriveHoldPriorLastPose;
    this->ForceAnimResetIfPriorAnimDrivesToSameTags = false;
    this->PoseDriveMode = ERagdollPoseDrivingMode::Inactive;
    this->PoseDriveBlendTime = 0.00f;
    this->StrengthOverTime = NULL;
    this->StrengthBlendInTime = 0.10f;
    this->CommitToGetupPose = false;
    this->EndBehavior = false;
    this->AllowRemoval = false;
    this->AllowHibrnate = false;
    this->ForceFreezeInPlace = false;
}

