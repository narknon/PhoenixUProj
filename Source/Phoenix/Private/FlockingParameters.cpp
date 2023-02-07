#include "FlockingParameters.h"

FFlockingParameters::FFlockingParameters() {
    this->Follow = 0.00f;
    this->FollowLag = 0.00f;
    this->AwayDamping = 0.00f;
    this->MinFollowDistance = 0.00f;
    this->MaxFollowDistance = 0.00f;
    this->bEnforceMaxFollowDistance = false;
    this->Separation = 0.00f;
    this->SeparationDistance = 0.00f;
    this->Clusters = 0;
    this->Alignment = 0.00f;
    this->Cohesion = 0.00f;
    this->bEnforceMaxSpeed = false;
    this->MaxSpeed = 0.00f;
    this->VelocityDamping = 0.00f;
    this->bAlign = false;
    this->LocalSpace = 0.00f;
    this->bUseDynamicLeader = false;
    this->SwitchDynamicLeaderTimeMin = 0.00f;
    this->SwitchDynamicLeaderTimeMax = 0.00f;
    this->StrengthMod = 0.00f;
    this->NumericMaxBounds = 0.00f;
    this->NumericSpeedLimit = 0.00f;
}

