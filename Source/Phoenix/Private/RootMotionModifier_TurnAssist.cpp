#include "RootMotionModifier_TurnAssist.h"

class AAmbulatory_Character;

void URootMotionModifier_TurnAssist::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

void URootMotionModifier_TurnAssist::CharacterRotatedBySupport(FRotator AmountRotated) {
}

URootMotionModifier_TurnAssist::URootMotionModifier_TurnAssist() {
    this->RootYawRemaining = 0.00f;
    this->RootYawOffset = 0.00f;
    this->RootYawSampleTime = -1.00f;
    this->bRootYawRemainingInitialized = false;
    this->ElapsedTime = 0.00f;
    this->ScaledElapsedTime = 0.00f;
    this->bValidFacingTargets = false;
}

