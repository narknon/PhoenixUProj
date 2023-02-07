#include "SceneRigAnimationTrackPlacementOptions.h"

FSceneRigAnimationTrackPlacementOptions::FSceneRigAnimationTrackPlacementOptions() {
    this->ConstrainedToPlacement = false;
    this->bUnscaleHipsBone = false;
    this->ConstraintMode = ESceneRigAnimationTrackConstraintMode::ConstrainComponent;
    this->PlacementRespectsBlends = false;
    this->Placement = NULL;
    this->PlacementOffset = NULL;
}

