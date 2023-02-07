#pragma once
#include "CoreMinimal.h"
#include "ELineRule_LayeredAnimationLipSyncIntensityType.generated.h"

UENUM(BlueprintType)
enum class ELineRule_LayeredAnimationLipSyncIntensityType : uint8 {
    LowToHigh,
    High,
    MediumToHigh,
    Medium,
    LowToMedium,
    Low,
    ELineRule_MAX UMETA(Hidden),
};

