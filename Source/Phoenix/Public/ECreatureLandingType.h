#pragma once
#include "CoreMinimal.h"
#include "ECreatureLandingType.generated.h"

UENUM(BlueprintType)
enum class ECreatureLandingType : uint8 {
    None,
    Standing,
    Gallop,
    Trot,
    FromHover,
    Num,
};

