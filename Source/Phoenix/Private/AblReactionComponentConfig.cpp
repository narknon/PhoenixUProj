#include "AblReactionComponentConfig.h"

UAblReactionComponentConfig::UAblReactionComponentConfig() {
    this->DefaultFallingAbility = NULL;
    this->DefaultRagdollAbility = NULL;
    this->RecentlyOnFireTime = 0.50f;
    this->InAirDistanceFromGround = 30.00f;
    this->bDefaultCanReactToAllies = true;
}

