#include "RigUnit_FourBoneIK.h"

FRigUnit_FourBoneIK::FRigUnit_FourBoneIK() {
    this->TranslationLimitDistance = 0.00f;
    this->StretchToMaxExtension = 0.00f;
    this->MaxExtensionPercentage = 0.00f;
    this->PoleVectorLengthMultiplier = 0.00f;
    this->bEnableStretch = false;
    this->StretchStartRatio = 0.00f;
    this->StretchMaximumRatio = 0.00f;
    this->weight = 0.00f;
}

