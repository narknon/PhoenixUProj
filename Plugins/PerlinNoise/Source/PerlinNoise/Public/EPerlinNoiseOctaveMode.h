#pragma once
#include "CoreMinimal.h"
#include "EPerlinNoiseOctaveMode.generated.h"

UENUM(BlueprintType)
enum class EPerlinNoiseOctaveMode : uint8 {
    All,
    Odd,
    Even,
    Thirds,
};

