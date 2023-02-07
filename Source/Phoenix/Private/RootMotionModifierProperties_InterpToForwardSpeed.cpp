#include "RootMotionModifierProperties_InterpToForwardSpeed.h"

URootMotionModifierProperties_InterpToForwardSpeed::URootMotionModifierProperties_InterpToForwardSpeed() {
    this->DesiredSpeedState = ERootMotModDesiredSpeed::UseProvided;
    this->DesiredSpeed = 1.00f;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->InterpSpeed = 1.00f;
}

