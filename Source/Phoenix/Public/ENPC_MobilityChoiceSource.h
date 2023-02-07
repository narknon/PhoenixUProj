#pragma once
#include "CoreMinimal.h"
#include "ENPC_MobilityChoiceSource.generated.h"

UENUM(BlueprintType)
enum class ENPC_MobilityChoiceSource : uint8 {
    Distance,
    ENPC_MAX UMETA(Hidden),
};

