#pragma once
#include "CoreMinimal.h"
#include "EFactsheetButtonState.generated.h"

UENUM(BlueprintType)
enum class EFactsheetButtonState : uint8 {
    FS_NONE,
    FS_UNKNOWN,
    FS_QUERY,
    FS_REDIRECT,
    FS_KNOWN,
    FS_MAX UMETA(Hidden),
};

