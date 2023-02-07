#include "WandCastInfo.h"

FWandCastInfo::FWandCastInfo() {
    this->WandCastType = EWandCastType::None;
    this->LastWandCastType = EWandCastType::None;
    this->PreWandCastState = EPreWandCastState::None;
    this->AnticipationWandCastState = EPreWandCastState::None;
    this->LastWandCastState = ELastWandCastState::None;
    this->TimeAtLastAttack = 0.00f;
    this->LastDiscreteAngle = 0.00f;
    this->LastBaseAttackIndex = 0;
    this->AttackCount = 0;
    this->bMelee = false;
    this->bComboFinisher = false;
    this->bTransitionAnimation = false;
}

