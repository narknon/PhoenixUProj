#pragma once
#include "CoreMinimal.h"
#include "EAnimateLightColorIntensityBlend.generated.h"

UENUM(BlueprintType)
enum class EAnimateLightColorIntensityBlend : uint8 {
    Replace,
    Multiply,
    Additive,
};

