#include "ConversationOption.h"

FConversationOption::FConversationOption() {
    this->MenuNode_ID = 0;
    this->Disabled = false;
    this->Reason_Tooltip = EAvaAudioDialogueConditionFailedLineHandling::CFH_Suppress_Display;
    this->PreviouslyUsed = false;
}

