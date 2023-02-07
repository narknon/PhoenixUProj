#include "Goblin_AttackSpeedChoice.h"

UGoblin_AttackSpeedChoice::UGoblin_AttackSpeedChoice() {
    this->SplitDistance = 1200.00f;
    this->ChangeTime = 1.50f;
    this->CloserSpeed = 140.00f;
    this->FurtherSpeed = 380.00f;
    this->RetreatDistance = 500.00f;
    this->RetreatTimeSinceAttack = 3.00f;
    this->RetreatSpeed = 380.00f;
}

