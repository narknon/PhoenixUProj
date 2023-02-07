#include "RagdollSensoryRange.h"

FRagdollSensoryRange::FRagdollSensoryRange() {
    this->SensoryValue = ERagdollSensoryRangeValueEnum::RSRVE_HeightAboveGround;
    this->Min = 0.00f;
    this->Max = 0.00f;
    this->IfOutOfRange = false;
}

