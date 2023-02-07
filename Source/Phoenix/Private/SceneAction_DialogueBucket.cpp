#include "SceneAction_DialogueBucket.h"

USceneAction_DialogueBucket::USceneAction_DialogueBucket() {
    this->RepeatDelay = NULL;
    this->CutoffDialogueAtFinish = false;
    this->AtLocation = NULL;
    this->RestrictDialogueByProximity = true;
    this->ProximityRadius = 600.00f;
}

