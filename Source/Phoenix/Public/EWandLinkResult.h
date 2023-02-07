#pragma once
#include "CoreMinimal.h"
#include "EWandLinkResult.generated.h"

UENUM(BlueprintType)
enum class EWandLinkResult : uint8 {
    LethalExplode,
    NonLethalGetup,
    NonLethalProne,
    HarlowEnd,
};

