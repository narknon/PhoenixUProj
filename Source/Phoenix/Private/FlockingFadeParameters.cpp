#include "FlockingFadeParameters.h"

FFlockingFadeParameters::FFlockingFadeParameters() {
    this->AutoStartFade = 0.00f;
    this->bAutoStartFade = false;
    this->TransitionWidth = 0.00f;
    this->RadiusTimeConstant = 0.00f;
    this->bDynamicBounds = false;
    this->bKillActorWhenDone = false;
}

