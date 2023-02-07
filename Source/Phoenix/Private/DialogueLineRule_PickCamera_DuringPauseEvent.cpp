#include "DialogueLineRule_PickCamera_DuringPauseEvent.h"

UDialogueLineRule_PickCamera_DuringPauseEvent::UDialogueLineRule_PickCamera_DuringPauseEvent() {
    this->DurationThreshold = 0.00f;
    this->DurationVariability = 0.00f;
    this->ShowBeforePause = 0.00f;
    this->ShowBeforePauseVariability = 0.00f;
    this->ShowAfterPause = 0.00f;
    this->ShowAfterPauseVariability = 0.00f;
    this->CombinePausesThreshold = 0.00f;
    this->CombinePauseThresholdVariability = 0.00f;
}

