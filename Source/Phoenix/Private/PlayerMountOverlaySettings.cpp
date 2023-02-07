#include "PlayerMountOverlaySettings.h"

UPlayerMountOverlaySettings::UPlayerMountOverlaySettings() {
    this->TeleportTimer = 5.00f;
    this->FadeOutTimer = 5.00f;
    this->FadeInTeleportTimer = 1.00f;
    this->FadeInExitTimer = 0.50f;
    this->FadeHoldTimer = 0.25f;
    this->bDisableSpeedupInside = true;
    this->bDisableSpeedupUnlessFacing = false;
    this->bPauseTimerWhenFacing = false;
    this->FacingAngle = 60.00f;
    this->FadeAlpha = 1.00f;
    this->ResetTimer = 0.01f;
}

