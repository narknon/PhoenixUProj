#pragma once
#include "CoreMinimal.h"
#include "EMinimapInstanceIconFlags.generated.h"

UENUM(BlueprintType)
enum EMinimapInstanceIconFlags {
    MAP_INSTANCE_ICON_FLAG_ICON,
    MAP_INSTANCE_ICON_FLAG_UP_ARROW = 0x2,
    MAP_INSTANCE_ICON_FLAG_DOWN_ARROW = 0x4,
    MAP_INSTANCE_ICON_FLAG_HIGHLIGHT = 0x8,
    MAP_INSTANCE_ICON_FLAG_MAX UMETA(Hidden),
};

