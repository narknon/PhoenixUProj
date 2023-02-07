#include "RagdollSensoryBehavior.h"

FRagdollSensoryBehavior::FRagdollSensoryBehavior() {
    this->Relativity = ERagdollSensoryBehaviorEnum::RSBE_CurrentlyActive;
    this->Behavior = NULL;
    this->Status = false;
}

