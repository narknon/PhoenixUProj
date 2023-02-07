#pragma once
#include "CoreMinimal.h"
#include "ACLVisualFidelityChangeResult.generated.h"

UENUM(BlueprintType)
enum class ACLVisualFidelityChangeResult : uint8 {
    Dispatched,
    Completed,
    Failed,
};

