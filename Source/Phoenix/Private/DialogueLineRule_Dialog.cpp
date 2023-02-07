#include "DialogueLineRule_Dialog.h"

UDialogueLineRule_Dialog::UDialogueLineRule_Dialog() {
    this->UseSameSpeakerPreAndPostRoll = false;
    this->UseDifferentSpeakerPreAndPostRoll = false;
    this->SameSpeakerDelayBetweenLines = 0.00f;
    this->DifferentSpeakerDelayBetweenLines = 0.00f;
    this->FirstConversationDelay = 0.05f;
    this->LaterConversationDelay = 0.05f;
    this->bEnableDialogueSkipping = true;
    this->bEnableGameOptions = false;
}

