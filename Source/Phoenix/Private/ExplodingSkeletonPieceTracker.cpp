#include "ExplodingSkeletonPieceTracker.h"

FExplodingSkeletonPieceTracker::FExplodingSkeletonPieceTracker() {
    this->Piece = NULL;
    this->ActivationDelay = 0.00f;
    this->CollisionDelay = 0.00f;
    this->Timeout = 0.00f;
    this->FadeOut = 0.00f;
    this->bIsSimulatingPhysics = false;
    this->bEnabledCollisions = false;
    this->bFadingOut = false;
    this->bSuspended = false;
}

