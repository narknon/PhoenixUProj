#include "AblNpcCollisionTask.h"

UAblNpcCollisionTask::UAblNpcCollisionTask() {
    this->bOverrideSpellResponse = false;
    this->bOverrideWeaponResponse = false;
    this->bOverrideAimConeResponse = false;
    this->bOverridePawnResponse = false;
    this->TaskSpellResponse = ECR_Ignore;
    this->TaskWeaponResponse = ECR_Ignore;
    this->TaskAimConeResponse = ECR_Ignore;
    this->TaskPawnResponse = ECR_Ignore;
}

