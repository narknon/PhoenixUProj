#pragma once
#include "CoreMinimal.h"
#include "EBreakableState.generated.h"

UENUM(BlueprintType)
enum class EBreakableState : uint8 {
    Inactive,
    Unbroken,
    Broken,
};

