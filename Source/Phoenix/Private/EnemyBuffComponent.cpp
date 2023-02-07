#include "EnemyBuffComponent.h"

class AActor;

void UEnemyBuffComponent::EnableBuff(AActor* pActorMaster) {
}

UEnemyBuffComponent::UEnemyBuffComponent() {
    this->bIsMaster = false;
    this->validTargetRadius = 800.00f;
    this->healRatePercentagePerSec = 10.00f;
    this->buffTypeEnum = EEnemyBuffTypeEnum::EBC_Health;
    this->BuffMaxActiveTime = 15.00f;
    this->bAllowHealthBuff = true;
    this->bAllowWeaponBuff = true;
    this->pBeamFX = NULL;
    this->pBuffEmitterFX = NULL;
    this->pBuffEmitterFX2 = NULL;
    this->pBuffEmitterFX3 = NULL;
    this->pBuffEmitterFX4 = NULL;
    this->pBuffEmitterFXObj.AddDefaulted(2);
    this->pBuffEmitterFX2Obj.AddDefaulted(2);
    this->bIsDisabled = true;
}

