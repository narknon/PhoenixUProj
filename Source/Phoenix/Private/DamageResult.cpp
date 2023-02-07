#include "DamageResult.h"

FDamageResult::FDamageResult() {
    this->Victim = NULL;
    this->Instigator = NULL;
    this->SpellTool = NULL;
    this->MunitionAsset = NULL;
    this->DamageAmount = 0.00f;
    this->BaseDamageAmount = 0.00f;
    this->RemainingHealth = 0.00f;
    this->bNearDeathKneeling = false;
    this->bDeadlyAttack = false;
    this->bCursedDamage = false;
    this->bDeflection = false;
    this->bPerfectDeflection = false;
    this->bFinisher = false;
}

