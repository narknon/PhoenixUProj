#include "NamedPoint.h"

ANamedPoint::ANamedPoint() {
    this->m_bAppendLevelName = true;
    this->VolumeType = EVolumeType::None;
    this->Volume = NULL;
}

