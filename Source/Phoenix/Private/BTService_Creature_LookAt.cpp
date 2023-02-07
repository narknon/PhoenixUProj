#include "BTService_Creature_LookAt.h"

UBTService_Creature_LookAt::UBTService_Creature_LookAt() {
    this->Mode = ECreatureLookAtBehaviorMode::Disabled;
    this->bLookAtTarget = true;
    this->bAimAtTarget = false;
    this->bUrgentTarget = false;
}

