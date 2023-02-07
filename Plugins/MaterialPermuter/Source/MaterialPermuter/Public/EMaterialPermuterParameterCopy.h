#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterParameterCopy : uint8 {
    Default,
    AutoDetect,
    InterpParameters,
    UniformParameters,
    Exhaustive,
    FullDeep,
    NoCopy,
};

