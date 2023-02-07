#pragma once
#include "CoreMinimal.h"
#include "EStreamingPlaceholderPriority.generated.h"

UENUM(BlueprintType)
enum class EStreamingPlaceholderPriority : uint8 {
    HardLoad,
    High,
    Normal,
};

