#include "SceneAction_Adaptation.h"

USceneAction_Adaptation::USceneAction_Adaptation() {
    this->FeatherInTime = 0.50f;
    this->FeatherOutTime = 0.50f;
    this->Priority = 10000.00f;
    this->bHighestPossiblePriority = true;
    this->bEnabled = true;
}

