#pragma once
#include "CoreMinimal.h"
#include "EMissionStatus.generated.h"

UENUM(BlueprintType)
enum class EMissionStatus : uint8 {
    PreActive,
    Activating,
    Active,
    PostActive,
    Complete,
    Failed,
    Invalid,
    Count,
};

