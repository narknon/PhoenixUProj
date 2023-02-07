#include "FlightAnimationComponent.h"

UFlightAnimationComponent::UFlightAnimationComponent() {
    this->MinLiftSpeedPercent = 0.40f;
    this->MaxLiftSpeedPercent = 0.80f;
    this->MaxLiftAngle = 45.00f;
    this->MaxNeckRollAngle = 45.00f;
    this->MinAccelerationPercent = 0.50f;
    this->MaxAnimRate = 2.00f;
    this->MaxAccelerationPercent = 0.50f;
    this->MinVelocityPercent = 0.50f;
    this->MaxGlideTime = 10.00f;
    this->MinGlideResetTime = 1.00f;
    this->GlideTimeDescentSpeedThreshold = -10.00f;
}

