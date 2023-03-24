#include "NamedPoint.h"

ANamedPoint::ANamedPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_bAppendLevelName = true;
    this->VolumeType = EVolumeType::None;
    this->Volume = NULL;
}

