#pragma once
#include "CoreMinimal.h"
#include "EEmissiveAdaptationOverrideState.generated.h"

UENUM(BlueprintType)
enum class EEmissiveAdaptationOverrideState : uint8 {
    Begin,
    BlendIn,
    One,
    BlendOut,
    Complete,
};

