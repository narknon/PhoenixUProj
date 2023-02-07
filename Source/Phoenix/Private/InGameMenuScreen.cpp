#include "InGameMenuScreen.h"


void UInGameMenuScreen::MarkNeedsAutosave() {
}


UInGameMenuScreen::UInGameMenuScreen() {
    this->ThePageStack = NULL;
    this->NeedsAutosave = false;
}

