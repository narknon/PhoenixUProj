#include "NewTutorialInfo.h"

FNewTutorialInfo::FNewTutorialInfo() {
    this->ShouldShowCursor = false;
    this->ShouldHideCursorOnRemove = false;
    this->PlaySoundEffectOnCompletion = false;
    this->Modal = false;
    this->TransparencyType = ETutorialTransparency::Tutorial_Transparency_Translucent;
    this->PausesTheGame = false;
    this->ApplyBlur = false;
    this->ExpiryTimer = 0.00f;
    this->ExpiryTimerStartsAutomatically = false;
    this->ForceCompleteOnExpiry = false;
    this->AllowNonModalInput = false;
    this->TimeDilationFactor = 0.00f;
    this->Position = ETutorialPosition::Tutorial_TopLeft;
    this->PreDelay = 0.00f;
    this->PostDelay = 0.00f;
    this->CompletionButton = EUMGInputAction::UMGConfirm;
    this->MustHoldCompletionButton = false;
    this->VisibleOverMenu = false;
    this->OpenPauseMenuOnComplete = false;
    this->PauseMenuLockToPage = false;
}

