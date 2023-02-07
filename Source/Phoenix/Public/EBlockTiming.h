#pragma once
#include "CoreMinimal.h"
#include "EBlockTiming.generated.h"

UENUM(BlueprintType)
enum class EBlockTiming : uint8 {
    Block_Normal,
    Block_Perfect,
    Block_MAX UMETA(Hidden),
};

