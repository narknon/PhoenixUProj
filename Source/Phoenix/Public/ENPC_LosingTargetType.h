#pragma once
#include "CoreMinimal.h"
#include "ENPC_LosingTargetType.generated.h"

UENUM(BlueprintType)
enum class ENPC_LosingTargetType : uint8 {
    None,
    Seek,
    Death,
    Default,
    ENPC_MAX UMETA(Hidden),
};

