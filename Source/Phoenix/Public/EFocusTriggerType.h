#pragma once
#include "CoreMinimal.h"
#include "EFocusTriggerType.generated.h"

UENUM(BlueprintType)
enum EFocusTriggerType {
    FOCUSTRIGGER_TYPE_OPENWORLD,
    FOCUSTRIGGER_TYPE_NPC,
    FOCUSTRIGGER_TYPE_PLAYER,
    FOCUSTRIGGER_TYPE_WORLDEVENT,
    FOCUSTRIGGER_TYPE_COUNT,
    FOCUSTRIGGER_TYPE_MAX UMETA(Hidden),
};

