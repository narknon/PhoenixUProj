#pragma once
#include "CoreMinimal.h"
#include "ENPC_PlayerRelTargetTrackingType.generated.h"

UENUM(BlueprintType)
enum class ENPC_PlayerRelTargetTrackingType : uint8 {
    None,
    Range,
    Forced,
    Player,
    ENPC_MAX UMETA(Hidden),
};

