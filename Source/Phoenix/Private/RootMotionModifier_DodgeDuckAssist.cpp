#include "RootMotionModifier_DodgeDuckAssist.h"

class AAmbulatory_Character;

void URootMotionModifier_DodgeDuckAssist::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

URootMotionModifier_DodgeDuckAssist::URootMotionModifier_DodgeDuckAssist() {
    this->AngleOffset = 0.00f;
    this->YawRecovery = 0.00f;
}

