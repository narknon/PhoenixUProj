#include "AblTaskCondition_InteractionArchitectChild.h"

UAblTaskCondition_InteractionArchitectChild::UAblTaskCondition_InteractionArchitectChild() {
    this->Parent = NULL;
    this->bIncludeSelf = true;
    this->Project = EInteractionProject::Reactions;
}

