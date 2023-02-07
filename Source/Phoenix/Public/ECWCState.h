#pragma once
#include "CoreMinimal.h"
#include "ECWCState.generated.h"

UENUM(BlueprintType)
enum class ECWCState : uint8 {
    None,
    CWCStart,
    CWCUpdated,
};

