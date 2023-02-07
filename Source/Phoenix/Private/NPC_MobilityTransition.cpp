#include "NPC_MobilityTransition.h"

FNPC_MobilityTransition::FNPC_MobilityTransition() {
    this->FromMobility = ENPC_Mobility::None;
    this->ToMobility = ENPC_Mobility::None;
    this->AbilityPtr = NULL;
}

