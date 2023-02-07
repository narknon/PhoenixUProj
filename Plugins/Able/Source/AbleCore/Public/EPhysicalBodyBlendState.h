#pragma once
#include "CoreMinimal.h"
#include "EPhysicalBodyBlendState.generated.h"

UENUM(BlueprintType)
enum class EPhysicalBodyBlendState : uint8 {
    None,
    BlendIn,
    BlendOut,
    Destroy,
};

