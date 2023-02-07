#pragma once
#include "CoreMinimal.h"
#include "ENPC_SecondaryCollisionResponse.generated.h"

UENUM(BlueprintType)
enum class ENPC_SecondaryCollisionResponse : uint8 {
    None,
    Attack,
    PushAway,
    ENPC_MAX UMETA(Hidden),
};

