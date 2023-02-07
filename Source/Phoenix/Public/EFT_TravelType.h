#pragma once
#include "CoreMinimal.h"
#include "EFT_TravelType.generated.h"

UENUM(BlueprintType)
enum class EFT_TravelType : uint8 {
    NormalFastTravelOnly,
    UseFastTravelCVar,
    UnloadFastTravelOnly,
    EFT_MAX UMETA(Hidden),
};

