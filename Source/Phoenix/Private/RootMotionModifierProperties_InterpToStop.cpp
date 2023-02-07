#include "RootMotionModifierProperties_InterpToStop.h"

URootMotionModifierProperties_InterpToStop::URootMotionModifierProperties_InterpToStop() {
    this->ToStopInterpType = ECustomInterpType::Interp;
    this->ToStopInterpSpeed = 0.90f;
    this->ToStopTotalTime = 0.20f;
}

