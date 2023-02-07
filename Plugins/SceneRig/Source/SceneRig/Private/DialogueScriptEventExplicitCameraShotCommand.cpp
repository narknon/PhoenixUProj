#include "DialogueScriptEventExplicitCameraShotCommand.h"

UDialogueScriptEventExplicitCameraShotCommand::UDialogueScriptEventExplicitCameraShotCommand() {
    this->CameraShot = NULL;
    this->LookAt = ECommandLookAtType::Speaker;
    this->BlockLineImplicitCameraChanges = true;
    this->BlockEndingCameraChanges = false;
}

