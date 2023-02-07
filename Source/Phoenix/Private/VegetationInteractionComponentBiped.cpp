#include "VegetationInteractionComponentBiped.h"

UVegetationInteractionComponentBiped::UVegetationInteractionComponentBiped() {
    this->Priority = 0.00f;
    this->InnerRadiusFactor = 0.10f;
    this->OuterRadiusFactor = 4.00f;
    this->ForceScalingMultiplierMin = 0.50f;
    this->ForceScalingMultiplierMax = 1.00f;
    this->MaxAngleMultiplierMin = 0.75f;
    this->MaxAngleMultiplierMax = 1.00f;
    this->MaxVelocityMS = 3.00f;
    this->RotationalVelocityDegreesSec = 45.00f;
    this->FirstOrderDamping = 0.35f;
    this->SecondOrderDamping = 0.25f;
    this->SecondOrderNaturalFrequency = 3.00f;
    this->bSecondOrder = false;
    this->SpringMass = 0.00f;
    this->SpringMassVelocity = 0.00f;
}

