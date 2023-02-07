#include "FrontendSubsystem.h"

class UObject;

void UFrontendSubsystem::ReleaseTitleScreen(const UObject* LienHolder, FName LienholderName) {
}

bool UFrontendSubsystem::IsTitleScreenHeld(const UObject* WorldContextObject) {
    return false;
}

void UFrontendSubsystem::HoldTitleScreen(const UObject* LienHolder, FName LienholderName) {
}

UFrontendSubsystem::UFrontendSubsystem() {
}

