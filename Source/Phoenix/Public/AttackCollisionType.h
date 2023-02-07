#pragma once
#include "CoreMinimal.h"
#include "AttackCollisionType.generated.h"

UENUM(BlueprintType)
enum class AttackCollisionType : uint8 {
    LeftHandWeapon,
    RightHandWeapon,
    BodyCapsule,
    LeftAndRight,
    All,
};

