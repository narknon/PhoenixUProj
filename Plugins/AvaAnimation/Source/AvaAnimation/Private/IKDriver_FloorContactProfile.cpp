#include "IKDriver_FloorContactProfile.h"

FIKDriver_FloorContactProfile::FIKDriver_FloorContactProfile() {
    this->SupportType = FCPSupportType::Ignore;
    this->MovementType = FCPMovementType::Ignore;
    this->BlendInTime = 0.00f;
}

