#include "RootMotionModifier_FacingAssist.h"

class AAmbulatory_Character;

void URootMotionModifier_FacingAssist::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

URootMotionModifier_FacingAssist::URootMotionModifier_FacingAssist() {
    this->StartHeading = 0.00f;
    this->ElapsedTime = 0.00f;
}

