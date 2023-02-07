#pragma once
#include "CoreMinimal.h"
#include "EFlyingStairState.generated.h"

UENUM(BlueprintType)
enum class EFlyingStairState : uint8 {
    Unbuilt,
    Building,
    Built,
    Demolishing,
    FlagForDemolishing,
};

