#include "DialogueScriptEventEmotionCommand.h"

UDialogueScriptEventEmotionCommand::UDialogueScriptEventEmotionCommand() {
    this->Emotion = EFacialEmotion::NONE;
    this->For = ECommandForType::Listener;
    this->ForFacial = true;
    this->ForFullBody = true;
    this->BlendInTime = 0.50f;
    this->UseBeforeSpeaking = false;
    this->UseAfterSpeaking = true;
    this->PostLineActiveTime = 0.00f;
    this->OverrideHoldTime = false;
    this->HoldTime = 2.00f;
}

