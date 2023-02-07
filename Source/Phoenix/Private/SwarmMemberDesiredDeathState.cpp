#include "SwarmMemberDesiredDeathState.h"

FSwarmMemberDesiredDeathState::FSwarmMemberDesiredDeathState() {
    this->State = EGroundSwarmMemberState::Frozen;
    this->DeathLeapImpulseVariancePercent = 0.00f;
    this->DeathLeapCheckForActorCollision = EGroundSwarmingKillEventDeathLeapCollisionType::None;
    this->bDeathLeapAlignTowardsCenter = false;
    this->StateTimeout = 0.00f;
    this->bStateTimeout = false;
    this->Instigator = 0;
}

