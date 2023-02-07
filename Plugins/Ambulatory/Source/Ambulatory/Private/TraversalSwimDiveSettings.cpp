#include "TraversalSwimDiveSettings.h"

FTraversalSwimDiveSettings::FTraversalSwimDiveSettings() {
    this->DeepWaterCollisionChannel = ECC_WorldStatic;
    this->FallIntoWaterMinSpeed = 0.00f;
    this->FallIntoWaterMinTimeToImpact = 0.00f;
    this->FallIntoWaterMaxTimeToImpact = 0.00f;
    this->FallIntoWaterMinWaterDepth = 0.00f;
    this->DiveIntoWaterFwdSpeed = 0.00f;
    this->DiveIntoWaterUpImpulse = 0.00f;
    this->DiveIntoWaterImpulseDelay = 0.00f;
    this->DiveIntoWaterMaxHeight = 0.00f;
    this->DiveIntoWaterMinWaterDepth = 0.00f;
}

