#include "AblAnimationTagChooser_EnemyContainer.h"

UAblAnimationTagChooser_EnemyContainer::UAblAnimationTagChooser_EnemyContainer() {
    this->ContainerSource = EEnemy_TagContainer::None;
    this->bAddWeaponTags = false;
    this->bAddWeaponsTagsIfMatchAttackType = false;
    this->bAddDirectionalTags = false;
    this->bAddDirectionalTagsIfMatchAttackType = false;
}

