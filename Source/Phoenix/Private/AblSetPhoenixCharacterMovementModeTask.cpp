#include "AblSetPhoenixCharacterMovementModeTask.h"

UAblSetPhoenixCharacterMovementModeTask::UAblSetPhoenixCharacterMovementModeTask() {
    this->MovementMode = MOVE_Flying;
    this->Priority = EManagedMovementModePriority::Lowest;
}

