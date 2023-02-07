#include "RootMotionModifier_NPCMobilityTurnAssist.h"

class AAmbulatory_Character;

void URootMotionModifier_NPCMobilityTurnAssist::CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FRotator AmountRotated) {
}

void URootMotionModifier_NPCMobilityTurnAssist::CharacterRotatedBySupport(FRotator AmountRotated) {
}

URootMotionModifier_NPCMobilityTurnAssist::URootMotionModifier_NPCMobilityTurnAssist() {
    this->ElapsedTime = 0.00f;
    this->bApplyTranslateVec = false;
}

