#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityTargetType.generated.h"

UENUM(BlueprintType)
enum EAblAbilityTargetType {
    Self,
    Owner,
    Instigator,
    TargetActor,
    Camera,
    EnemyWeapon,
};

