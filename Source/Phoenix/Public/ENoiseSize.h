#pragma once
#include "CoreMinimal.h"
#include "ENoiseSize.generated.h"

UENUM(BlueprintType)
enum class ENoiseSize : uint8 {
    NoNoise,
    SmallNoise,
    MediumNoise,
    LargeNoise,
    HugeNoise,
    UseSize,
};

