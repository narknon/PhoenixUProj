#include "DialogueLineRule_PickCamera_EndingEvent.h"

UDialogueLineRule_PickCamera_EndingEvent::UDialogueLineRule_PickCamera_EndingEvent() {
    this->ForChoicesAtEnd = true;
    this->ForBeforeEmbeddedSequence = true;
    this->OffsetFromEnd = 0.00f;
    this->MinimumOffsetFromEnd = 0.00f;
    this->MinimumPreviousCameraLength = 0.00f;
}

