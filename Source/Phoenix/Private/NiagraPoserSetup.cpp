#include "NiagraPoserSetup.h"

FNiagraPoserSetup::FNiagraPoserSetup() {
    this->SkeletalMesh = NULL;
    this->NiagaraSystem = NULL;
    this->InitialDelay = 0.00f;
    this->LerpTime = 0.00f;
    this->bApplyAlphabetically = false;
    this->bHideUndrivenBones = false;
    this->bOnlyAnimateBones = false;
    this->bDoNotAnimateBones = false;
}

