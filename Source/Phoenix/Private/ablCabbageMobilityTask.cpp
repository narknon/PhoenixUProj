#include "ablCabbageMobilityTask.h"

UablCabbageMobilityTask::UablCabbageMobilityTask() {
    this->Speed = 200.00f;
    this->Gravity = -980.00f;
    this->ArcParam = 0.50f;
    this->m_actorBounceSfx = NULL;
    this->MobilityState = ECabbage_Mobility::Spawn;
    this->JumpBoost = 400.00f;
    this->MinBounceBack = 400.00f;
    this->MaxBounceBack = 600.00f;
    this->Deceleration = 200.00f;
    this->LandingSpeed = 100.00f;
}

