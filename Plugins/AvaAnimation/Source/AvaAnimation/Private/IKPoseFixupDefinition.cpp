#include "IKPoseFixupDefinition.h"

FIKPoseFixupDefinition::FIKPoseFixupDefinition() {
    this->ControlledOffsetProvider = NULL;
    this->bApplyBlendToAlphaCurve = false;
    this->BlendInTime = 0.00f;
    this->BlendOutTime = 0.00f;
    this->TranslateOnly = false;
    this->ReferenceScale = 0.00f;
    this->CushionAmount = 0.00f;
    this->TargetTransform = NULL;
    this->TargetOffsetProvider = NULL;
}

