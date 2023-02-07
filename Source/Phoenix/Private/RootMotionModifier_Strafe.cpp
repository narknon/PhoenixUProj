#include "RootMotionModifier_Strafe.h"

class AAmbulatory_Character;

void URootMotionModifier_Strafe::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FRotator AmountRotated) {
}

void URootMotionModifier_Strafe::CharacterRotatedBySupport(FRotator AmountRotated) {
}

URootMotionModifier_Strafe::URootMotionModifier_Strafe() {
    this->ElapsedTime = 0.00f;
}

