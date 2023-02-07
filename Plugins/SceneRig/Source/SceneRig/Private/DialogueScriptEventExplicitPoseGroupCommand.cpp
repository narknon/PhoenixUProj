#include "DialogueScriptEventExplicitPoseGroupCommand.h"

UDialogueScriptEventExplicitPoseGroupCommand::UDialogueScriptEventExplicitPoseGroupCommand() {
    this->PoseGroup = NULL;
    this->OverrideDuration = false;
    this->MinDurationSeconds = 6.00f;
    this->MaxDurationSeconds = 12.00f;
    this->For = ECommandForType::Speaker;
}

