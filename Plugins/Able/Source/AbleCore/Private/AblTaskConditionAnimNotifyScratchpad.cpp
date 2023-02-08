#include "AblTaskConditionAnimNotifyScratchpad.h"


void UAblTaskConditionAnimNotifyScratchpad::OnAnimationPlayed(float InCurrentTime, const UAnimationAsset* InAnimationAsset, const UAblAbilityContext* Context) {
}

UAblTaskConditionAnimNotifyScratchpad::UAblTaskConditionAnimNotifyScratchpad() {
    this->bEventReceived = false;
    this->bEventExists = false;
}

