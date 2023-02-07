#include "RootMotionModifier_Move.h"

class AAmbulatory_Character;

void URootMotionModifier_Move::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FRotator AmountRotated) {
}

void URootMotionModifier_Move::CharacterRotatedBySupport(FRotator AmountRotated) {
}

URootMotionModifier_Move::URootMotionModifier_Move() {
    this->StartingSpeed = 0.00f;
    this->ElapsedTime = 0.00f;
}

