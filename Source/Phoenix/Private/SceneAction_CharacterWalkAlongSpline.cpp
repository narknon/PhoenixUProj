#include "SceneAction_CharacterWalkAlongSpline.h"

USceneAction_CharacterWalkAlongSpline::USceneAction_CharacterWalkAlongSpline() {
    this->SplinePathActor = NULL;
    this->WalkSpeed = 156.00f;
    this->SplineFollowDirection = 1;
    this->SplineHorizontalOffset = 0.00f;
    this->SplineLookAheadDistance = 500.00f;
}

