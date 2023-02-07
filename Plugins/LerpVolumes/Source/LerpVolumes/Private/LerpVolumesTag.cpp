#include "LerpVolumesTag.h"

FLerpVolumesTag::FLerpVolumesTag() {
    this->AlphaTransition = 0.00f;
    this->bForceFullHistory = false;
    this->bOnlySetDefaultWWiseRTPCIfNotEmpty = false;
    this->DefaultValueMode = ELerpVolumesTagValueMode::FinalValue;
    this->RTPCValueMode = ELerpVolumesTagValueMode::FinalValue;
    this->HermesValueMode = ELerpVolumesTagValueMode::FinalValue;
}

