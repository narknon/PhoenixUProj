#include "RootMotionModifierProperties_Interact.h"

URootMotionModifierProperties_Interact::URootMotionModifierProperties_Interact() {
    this->UseTargetTracker = EInteractUseTargetTracker::FaceTracker;
    this->bUseActorFromTracker = false;
    this->SpecificTargetID = ETargetID::None;
    this->Properties = NULL;
}

