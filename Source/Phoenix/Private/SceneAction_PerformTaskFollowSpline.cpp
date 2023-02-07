#include "SceneAction_PerformTaskFollowSpline.h"

USceneAction_PerformTaskFollowSpline::USceneAction_PerformTaskFollowSpline() {
    this->SplineFollowerActor = NULL;
    this->FinishAction = EPerformTaskFinishAction::StopAndWait;
}

