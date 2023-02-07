#include "AblBranchConditionEnemyMoveEnd.h"

UAblBranchConditionEnemyMoveEnd::UAblBranchConditionEnemyMoveEnd() {
    this->MoveType = MoveEnd_Slide;
    this->SlideLinkEndXYTolerance = 100.00f;
    this->SlideLinkEndZTolerance = 100.00f;
    this->bSlideCheckSurfaceType = true;
}

