#pragma once
#include "CoreMinimal.h"
#include "EAnimBlendTickStyle.generated.h"

UENUM(BlueprintType)
enum class EAnimBlendTickStyle : uint8 {
    BlendTickBoth,
    BlendTickDest,
};

