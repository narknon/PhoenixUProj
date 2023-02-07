#include "TriggerEffect.h"

void UTriggerEffect::MarkForUpdate() {
}

UTriggerEffect::UTriggerEffect() {
    this->TriggerMode = TriggerModeEnum::Weapon;
    this->RightTrigger = true;
    this->LeftTrigger = false;
    this->WeaponStartPosition = 2;
    this->WeaponEndPosition = 7;
    this->WeaponStrength = 5;
    this->VibrationPosition = 8;
    this->VibrationFrequency = 200;
    this->VibrationAmplitude = 8;
    this->FeedbackPosition = 0;
    this->FeedbackStrength = 1;
}

