#include "AnimTrackPlacementOptions.h"

FAnimTrackPlacementOptions::FAnimTrackPlacementOptions() {
    this->PlacementIsValid = false;
    this->RootMotionIsValid = false;
    this->ConstrainedToPlacement = false;
    this->PlacementIsMoving = false;
    this->HandledByRequest = false;
    this->RootEvaluationMode = EAnimTrackRootMode::CompletelyIgnoreRoot;
    this->AccumulateRootMotion = false;
    this->PlacementProvider = NULL;
    this->AnimationPlacementOffset = NULL;
}

