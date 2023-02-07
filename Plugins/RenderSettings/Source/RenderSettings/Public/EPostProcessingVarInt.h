#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarInt.generated.h"

UENUM(BlueprintType)
enum class EPostProcessingVarInt : uint8 {
    None,
    ReflectionsType,
    DepthOfFieldBladeCount,
    MotionBlurTargetFPS,
};

