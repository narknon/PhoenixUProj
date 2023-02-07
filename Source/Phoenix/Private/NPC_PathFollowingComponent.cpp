#include "NPC_PathFollowingComponent.h"

bool UNPC_PathFollowingComponent::FindLinkOnCurrentPath(FVector& OutPos, float MinLookaheadDistance, float LookAheadTime) {
    return false;
}

UNPC_PathFollowingComponent::UNPC_PathFollowingComponent() {
    this->CharacterMoveComp = NULL;
    this->NPCComponent = NULL;
    this->bCanPausePathFollowingWhenBlocked = true;
    this->RepulsorRadiusMultiplier = 1.00f;
    this->RepulsorRadiusCushionMultiplier = 0.20f;
    this->RepulsorDetectionRadiusMultiplier = 10.00f;
    this->ResolveBlockedAllowableAngle = 135.00f;
    this->DirectionFilterRate = 1.00f;
    this->DirectionFilterRateMin = 0.10f;
    this->DirectionFilterRateMax = 0.30f;
    this->DirectionAvoidanceInterval = 0.00f;
    this->AvoidanceSlowdownScale = 0.80f;
}

