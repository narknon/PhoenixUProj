#include "AblBranchTaskScratchPad.h"



void UAblBranchTaskScratchPad::OnAnimationPlayed(float InCurrentTime, const UAnimationAsset* InAnimationAsset, const UAblAbilityContext* Context) {
}

UAblBranchTaskScratchPad::UAblBranchTaskScratchPad() {
    this->bEventReceived = false;
    this->bEventExists = false;
    this->bCanEverPassConditions = true;
}

