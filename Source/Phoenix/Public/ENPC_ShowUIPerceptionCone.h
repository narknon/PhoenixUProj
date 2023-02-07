#pragma once
#include "CoreMinimal.h"
#include "ENPC_ShowUIPerceptionCone.generated.h"

UENUM(BlueprintType)
enum class ENPC_ShowUIPerceptionCone : uint8 {
    Normal,
    Disillusionment,
    Invisible,
    ENPC_MAX UMETA(Hidden),
};

