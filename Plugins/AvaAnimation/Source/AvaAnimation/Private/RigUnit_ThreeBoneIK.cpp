#include "RigUnit_ThreeBoneIK.h"

FRigUnit_ThreeBoneIK::FRigUnit_ThreeBoneIK() {
    this->TranslationLimitDistance = 0.00f;
    this->StretchToMaxExtension = 0.00f;
    this->MaxExtensionPercentage = 0.00f;
    this->PoleVectorLengthMultiplier = 0.00f;
    this->bEnableStretch = false;
    this->StretchStartRatio = 0.00f;
    this->StretchMaximumRatio = 0.00f;
    this->weight = 0.00f;
}

