#pragma once
#include "CoreMinimal.h"
#include "EablNPC_FixedSource.generated.h"

UENUM(BlueprintType)
enum class EablNPC_FixedSource : uint8 {
    Param,
    External,
    EablNPC_MAX UMETA(Hidden),
};

