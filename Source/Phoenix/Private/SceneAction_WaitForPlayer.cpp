#include "SceneAction_WaitForPlayer.h"

USceneAction_WaitForPlayer::USceneAction_WaitForPlayer() {
    this->DistanceThreshold = 150.00f;
    this->bOrientTowardsPlayer = false;
    this->FinishAction = EPerformTaskFinishAction::StopAndWait;
}

