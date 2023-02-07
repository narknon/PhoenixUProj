#pragma once
#include "CoreMinimal.h"
#include "ESaveBlockReason.generated.h"

UENUM(BlueprintType)
enum class ESaveBlockReason : uint8 {
    BLOCK_SAVE_UNKNOWN,
    BLOCK_SAVE_PERFORMTASK,
    BLOCK_SAVE_COMBAT,
    BLOCK_SAVE_TUTORIAL,
    BLOCK_SAVE_CINEMATIC,
    BLOCK_SAVE_CONVERSATION,
    BLOCK_SAVE_MOUNT,
    BLOCK_SAVE_EXCLUSIVE_MISSION,
    BLOCK_SAVE_DUNGEON,
    BLOCK_SAVE_MAX UMETA(Hidden),
};

