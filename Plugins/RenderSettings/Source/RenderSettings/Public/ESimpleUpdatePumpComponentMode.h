#pragma once
#include "CoreMinimal.h"
#include "ESimpleUpdatePumpComponentMode.generated.h"

UENUM(BlueprintType)
enum class ESimpleUpdatePumpComponentMode : uint8 {
    UPM_ALWAYS,
    UPM_EDITORONLY,
    UPM_GAMEONLY,
    UPM_NEVER,
    UPM_MAX UMETA(Hidden),
};

