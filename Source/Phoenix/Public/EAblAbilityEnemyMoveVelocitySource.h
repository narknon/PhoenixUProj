#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityEnemyMoveVelocitySource.generated.h"

UENUM(BlueprintType)
enum EAblAbilityEnemyMoveVelocitySource {
    External,
    Fall,
    CustomForward,
    CustomBackward,
    Custom,
    Jump,
    Continued,
    Slide,
};

