#pragma once
#include "CoreMinimal.h"
#include "EForageableState.generated.h"

UENUM(BlueprintType)
enum class EForageableState : uint8 {
    Inactive,
    Idle,
    Collected,
};

