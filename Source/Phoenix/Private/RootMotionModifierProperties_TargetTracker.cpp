#include "RootMotionModifierProperties_TargetTracker.h"

URootMotionModifierProperties_TargetTracker::URootMotionModifierProperties_TargetTracker() {
    this->TargetType = ERootMotionModTargetType::FaceTracker;
    this->bGetActorFromTracker = false;
    this->GetActorFromTargetID = ETargetID::None;
    this->InterpType = ECustomInterpType::None;
    this->InterpSpeed = 1.00f;
}

