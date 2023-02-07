#include "AnimNode_MotionMatcher.h"

FAnimNode_MotionMatcher::FAnimNode_MotionMatcher() {
    this->PoseTable = NULL;
    this->GoalDelegate = NULL;
    this->Responsiveness = 0.00f;
    this->BonusForSameMotion = 0.00f;
    this->BlendDuration = 0.00f;
    this->bAnimationDrivesPill = false;
    this->bAlignRootDirection = false;
    this->bStrideWarping = false;
    this->bHoldFootPositionWhenPlanted = false;
    this->ShowGoal = false;
    this->ShowTrail = false;
    this->ShowBestPath = false;
    this->ShowFeet = false;
    this->ShowVelocity = false;
    this->ShowCapsuleVsAnimation = false;
    this->CandidatesToDrawPerFrame = 0.00f;
    this->TimeToHoldEachCandidate = 0.00f;
    this->CurrentAnimSequence = NULL;
}

