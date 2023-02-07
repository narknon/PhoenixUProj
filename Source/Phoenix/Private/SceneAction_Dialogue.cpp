#include "SceneAction_Dialogue.h"

USceneAction_Dialogue::USceneAction_Dialogue() {
    this->Line = NULL;
    this->StopWhenAttachedToDestroyed = false;
    this->CutoffDialogueAtFinish = false;
}

