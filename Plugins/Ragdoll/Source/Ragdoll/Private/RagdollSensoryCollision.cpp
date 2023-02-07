#include "RagdollSensoryCollision.h"

FRagdollSensoryCollision::FRagdollSensoryCollision() {
    this->ImpactImpulseMin = 0.00f;
    this->ImpactImpulseMax = 0.00f;
    this->IfOutOfRange = false;
    this->RequireNormalToWorldUpRealitiveRange = false;
    this->NormalToWorldUpAngleMin = 0.00f;
    this->NormalToWorldUpAngleMax = 0.00f;
    this->Status = false;
}

