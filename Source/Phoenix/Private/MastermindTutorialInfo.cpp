#include "MastermindTutorialInfo.h"

FMastermindTutorialInfo::FMastermindTutorialInfo() {
    this->bIsPlayingIntro = false;
    this->bIsPlayingOutro = false;
    this->bIsModal = false;
    this->bExpectsInput = false;
    this->CompletionButton = EUMGInputAction::UMGConfirm;
    this->MustHoldCompletionButton = false;
}

