#pragma once
#include "CoreMinimal.h"
#include "EAnimationRequestLayerBlendType.generated.h"

UENUM()
enum class EAnimationRequestLayerBlendType : int8 {
    Replacement,
    Additive,
    BlendAndReplace,
    BlendAndAdd,
    Modify,
};

