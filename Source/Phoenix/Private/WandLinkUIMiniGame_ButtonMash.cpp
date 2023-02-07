#include "WandLinkUIMiniGame_ButtonMash.h"

void UWandLinkUIMiniGame_ButtonMash::IncorrectButtonMashed() {
}

void UWandLinkUIMiniGame_ButtonMash::CorrectButtonMashed() {
}

void UWandLinkUIMiniGame_ButtonMash::CheatButtonSuccessPressed() {
}

void UWandLinkUIMiniGame_ButtonMash::CheatButtonFailPressed() {
}

UWandLinkUIMiniGame_ButtonMash::UWandLinkUIMiniGame_ButtonMash() {
    this->AntagonistStartingSurgeToPctInterpType = ECustomInterpType::EaseIn;
    this->AntagonistStartingSurgeToPctInterpSpeedOrExp = 0.70f;
    this->AntagonistStartingSurgeToPctInterpTime = 0.30f;
    this->ButtonMashTimeOut = 0.16f;
    this->WandLinkButtonMashInput = EWandLinkInputType::RandomFaceButton;
    this->ProtagonistAttackInterpType = ECustomInterpType::EaseInOut;
    this->ProtagonistAttackInterpSpeedOrExp = 0.70f;
    this->ProtagonistAttackInterpTime = 0.30f;
    this->FailDelay = 0.50f;
    this->SuccessDelay = 0.50f;
}

