#include "SpringFollowComponentSettings.h"

FSpringFollowComponentSettings::FSpringFollowComponentSettings() {
    this->AttachedMass = 0.00f;
    this->RadialConstraintMeters = 0.00f;
    this->RadialMinimumtMeters = 0.00f;
    this->SpringK = 0.00f;
    this->SpringB = 0.00f;
    this->Damping = 0.00f;
    this->RadialDamping = 0.00f;
    this->GravityFactor = 0.00f;
    this->SwirlForce = 0.00f;
}

