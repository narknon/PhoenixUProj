#include "PropOwl_AnimInstance.h"

UPropOwl_AnimInstance::UPropOwl_AnimInstance() {
    this->DesiredStance = ECreatureStance::Standing;
    this->InitStance = ECreatureStance::Standing;
    this->ReactToSpell = false;
}

