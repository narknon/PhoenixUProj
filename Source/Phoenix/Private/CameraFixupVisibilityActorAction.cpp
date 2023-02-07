#include "CameraFixupVisibilityActorAction.h"

UCameraFixupVisibilityActorAction::UCameraFixupVisibilityActorAction() {
    this->Priority = EManagedVisibilityPriority::PassiveCinematic;
    this->ShouldBeHidden = true;
    this->IncludeChildActors = true;
}

