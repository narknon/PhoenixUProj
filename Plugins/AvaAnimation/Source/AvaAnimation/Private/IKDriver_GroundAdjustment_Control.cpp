#include "IKDriver_GroundAdjustment_Control.h"

FIKDriver_GroundAdjustment_Control::FIKDriver_GroundAdjustment_Control() {
    this->TraceShape = EIKDriver_GroundAdjustment_TraceShape::Line;
    this->bTraceComplex = false;
    this->bRequireOnGroundForStepDown = false;
    this->MaxStepUpHeight = 0.00f;
    this->MaxStepDownHeight = 0.00f;
    this->MaxAdjustmentAngle = 0.00f;
    this->MaxControlHeight = 0.00f;
    this->MaxLegExtension = 0.00f;
}

