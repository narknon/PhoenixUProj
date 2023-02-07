#pragma once
#include "CoreMinimal.h"
#include "EEnemyWeaponTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EEnemyWeaponTypeEnum : uint8 {
    ESW_Default,
    ESW_Bola,
    ESW_Sword,
    ESW_Axe,
    ESW_Hammer,
    ESW_Mace,
    ESW_Spear,
    ESW_Katar,
    ESW_Shield,
    ESW_DarkWizardWand,
    ESW_Dagger,
    ESW_Meteor,
    ESW_MeteorPiece,
    ESW_Crossbow,
    ESW_MAX UMETA(Hidden),
};

