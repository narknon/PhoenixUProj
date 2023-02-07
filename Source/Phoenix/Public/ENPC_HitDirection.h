#pragma once
#include "CoreMinimal.h"
#include "ENPC_HitDirection.generated.h"

UENUM(BlueprintType)
enum class ENPC_HitDirection : uint8 {
    None,
    Front,
    Left,
    Right,
    Back,
    ENPC_MAX UMETA(Hidden),
};

