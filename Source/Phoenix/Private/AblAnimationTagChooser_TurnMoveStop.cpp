#include "AblAnimationTagChooser_TurnMoveStop.h"

UAblAnimationTagChooser_TurnMoveStop::UAblAnimationTagChooser_TurnMoveStop() {
    this->StickFlickTime = 0.10f;
    this->ShortStopTime = 1.00f;
    this->ShuffleStepInterpTime = 0.40f;
    this->PivotStopTime = 0.55f;
    this->StartStopTime = 0.40f;
    this->NoRootStopTime = 0.30f;
    this->bEnableFwdStart2Stop = false;
}

