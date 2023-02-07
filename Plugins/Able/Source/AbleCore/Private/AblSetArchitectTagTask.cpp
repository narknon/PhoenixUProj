#include "AblSetArchitectTagTask.h"

UAblSetArchitectTagTask::UAblSetArchitectTagTask() {
    this->RemoveTagAtEndOfTask = false;
    this->AddThisTag = false;
    this->RemoveThisTag = false;
    this->Type = ANIMATION_ARCHITECT;
    this->ApplyToAnimationArchitect = false;
    this->ApplyToInteractionArchitect = false;
}

