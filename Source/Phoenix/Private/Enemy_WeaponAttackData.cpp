#include "Enemy_WeaponAttackData.h"

FEnemy_WeaponAttackData::FEnemy_WeaponAttackData() {
    this->TransientWeapon = NULL;
    this->EquipedSelectScale = 0.00f;
    this->StoredSelectScale = 0.00f;
    this->SeekSelectScale = 0.00f;
    this->bDeferredEquip = false;
    this->bDoNotUseWeaponForAttack = false;
    this->bDestroyTransientWeaponOnDeactivate = false;
}

