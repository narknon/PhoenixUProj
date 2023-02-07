#include "ArrestoMomentumSpellTool.h"

AArrestoMomentumSpellTool::AArrestoMomentumSpellTool() {
    this->SlowDownTime = 1.00f;
    this->SpeedUpTime = 0.50f;
    this->ObjectMassMax = 250.00f;
    this->CharacterMassMax = 250.00f;
    this->MaxLinearDamping = 250.00f;
    this->MaxAngularDamping = 250.00f;
    this->CharacterTimeDilation = 0.10f;
    this->AOEMunition = NULL;
}

