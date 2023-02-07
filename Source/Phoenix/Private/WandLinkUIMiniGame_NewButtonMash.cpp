#include "WandLinkUIMiniGame_NewButtonMash.h"

void UWandLinkUIMiniGame_NewButtonMash::SuccessTimerExpired() {
}

void UWandLinkUIMiniGame_NewButtonMash::SuccessComboButtonReleased() {
}

void UWandLinkUIMiniGame_NewButtonMash::SuccessComboButtonPressed() {
}

void UWandLinkUIMiniGame_NewButtonMash::SuccessButtonPressed() {
}

void UWandLinkUIMiniGame_NewButtonMash::IncorrectSuccessButtonPressed() {
}

void UWandLinkUIMiniGame_NewButtonMash::IncorrectButtonMashed() {
}

void UWandLinkUIMiniGame_NewButtonMash::FailTimerExpired() {
}

void UWandLinkUIMiniGame_NewButtonMash::CorrectButtonMashed() {
}

void UWandLinkUIMiniGame_NewButtonMash::CheatButtonSuccessPressed() {
}

void UWandLinkUIMiniGame_NewButtonMash::CheatButtonFailPressed() {
}

UWandLinkUIMiniGame_NewButtonMash::UWandLinkUIMiniGame_NewButtonMash() {
    this->AntagonistAttackSpeed = 10.00f;
    this->ButtonMashMeterInterpInSpeed = 1.30f;
    this->ButtonMashTimeOut = 0.16f;
    this->ButtonMashDecreaseRate = -0.20f;
    this->ButtonMashNearSuccessCheck = 0.05f;
    this->WandLinkButtonMashInput = EWandLinkInputType::LeftShoulderButton;
    this->WandLinkSuccessInput = EWandLinkInputType::LeftShoulderButton;
    this->ProtagonistSuccessSurge = 50.00f;
    this->ProtagonistAttackInterpType = ECustomInterpType::EaseInOut;
    this->ProtagonistAttackInterpSpeedOrExp = 0.70f;
    this->ProtagonistAttackInterpTime = 0.30f;
    this->ProtagonistFailSurge = 10.00f;
    this->FailDelay = 0.50f;
    this->FailAttackonistSpeedMultiplier = 0.50f;
    this->SuccessDelay = 0.50f;
}

