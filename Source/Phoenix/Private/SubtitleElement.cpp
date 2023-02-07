#include "SubtitleElement.h"

void USubtitleElement::InitAudioDialogueLineData(const FAudioDialogueLineData& AudioDialogueLineData) {
}

USubtitleElement::USubtitleElement() : UUserWidget(FObjectInitializer::Get()) {
    this->AudioPriority = 0;
    this->bAudioEndedRecieved = false;
}

