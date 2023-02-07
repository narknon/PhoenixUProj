#pragma once
#include "CoreMinimal.h"
#include "EPlayerRenderTarget.generated.h"

UENUM(BlueprintType)
enum class EPlayerRenderTarget : uint8 {
    PRT_Ripple,
    PRT_WaveDisplacements,
    PRT_WaveFoam,
    PRT_Count,
    PRT_MAX UMETA(Hidden),
};

