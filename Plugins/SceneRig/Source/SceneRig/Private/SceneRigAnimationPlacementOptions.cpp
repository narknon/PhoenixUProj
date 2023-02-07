#include "SceneRigAnimationPlacementOptions.h"

FSceneRigAnimationPlacementOptions::FSceneRigAnimationPlacementOptions() {
    this->RootEvaluationMode = EAnimTrackRootMode::CompletelyIgnoreRoot;
    this->RootBlendMode = ESceneRigAnimationRootBlendMode::BlendRootWithAnimation;
    this->BlendInRootBlendMode = ESceneRigAnimationRootBlendMode::BlendRootWithAnimation;
    this->BlendOutRootBlendMode = ESceneRigAnimationRootBlendMode::BlendRootWithAnimation;
    this->AccumulateRootMotion = false;
    this->ConstrainedToPlacement = NULL;
    this->PlacementRespectsBlends = NULL;
    this->PlacementIsMoving = NULL;
    this->Placement = NULL;
    this->PlacementOffset = NULL;
}

