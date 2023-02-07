#pragma once
#include "CoreMinimal.h"
#include "EOcclusionOption.generated.h"

UENUM(BlueprintType)
enum EOcclusionOption {
    OcclusionOff,
    OcclusionOnceOnPost,
    OcclusionTick,
};

