#pragma once
#include "CoreMinimal.h"
#include "EUpdatePumpComponentMode.generated.h"

UENUM(BlueprintType)
enum class EUpdatePumpComponentMode : uint8 {
    UPM_ALWAYS,
    UPM_EDITORONLY,
    UPM_GAMEONLY,
    UPM_NEVER,
    UPM_MAX UMETA(Hidden),
};

