#include "AIPerformTaskApparateToLocation.h"

class UScheduledEntity;

void UAIPerformTaskApparateToLocation::OnApparateOutCompleted(UScheduledEntity* InScheduledEntity, int32 ActivityTypeBits) {
}

UAIPerformTaskApparateToLocation::UAIPerformTaskApparateToLocation() {
    this->ApparateInAblAbility = NULL;
    this->ApparateOutAblAbility = NULL;
}

