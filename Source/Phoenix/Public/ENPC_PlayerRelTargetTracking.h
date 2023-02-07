#pragma once
#include "CoreMinimal.h"
#include "ENPC_PlayerRelTargetTracking.generated.h"

UENUM(BlueprintType)
enum class ENPC_PlayerRelTargetTracking : uint8 {
    None,
    Aware,
    Alert,
    Aggro,
    Combat,
    ENPC_MAX UMETA(Hidden),
};

