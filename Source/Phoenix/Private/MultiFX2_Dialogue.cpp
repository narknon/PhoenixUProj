#include "MultiFX2_Dialogue.h"

UMultiFX2_Dialogue::UMultiFX2_Dialogue() {
    this->DialogueEvent = NULL;
    this->bStopWhenAttachedToDestroyed = false;
    this->flags = AvaAudioDialogueFlags::DLGFLAG_None;
    this->bIgnoreDeactivate = true;
}

