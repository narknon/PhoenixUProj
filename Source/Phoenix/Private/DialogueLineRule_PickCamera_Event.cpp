#include "DialogueLineRule_PickCamera_Event.h"

UDialogueLineRule_PickCamera_Event::UDialogueLineRule_PickCamera_Event() {
    this->Enabled = true;
    this->Priority = EManagedCameraPriority::ActiveCinematic;
}

