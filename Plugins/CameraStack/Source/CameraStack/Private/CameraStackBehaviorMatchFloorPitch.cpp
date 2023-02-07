#include "CameraStackBehaviorMatchFloorPitch.h"

UCameraStackBehaviorMatchFloorPitch::UCameraStackBehaviorMatchFloorPitch() {
    this->bDrawDebug = false;
    this->TraceTagName = TEXT("SpringArm");
    this->TraceLength = 200.00f;
    this->TraceHeight = 100.00f;
    this->TraceDepth = 300.00f;
    this->PitchScaleUp = 0.50f;
    this->PitchScaleDown = 1.00f;
    this->PitchScaleDrop = 1.00f;
    this->ProbeSize = 12.00f;
    this->ProbeChannel = ECC_Camera;
    this->InterpSpeed = 1.00f;
    this->InterpSpeedDrop = 0.50f;
}

