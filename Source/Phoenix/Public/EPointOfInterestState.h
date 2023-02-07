#pragma once
#include "CoreMinimal.h"
#include "EPointOfInterestState.generated.h"

UENUM(BlueprintType)
enum class EPointOfInterestState : uint8 {
    Found,
    Known,
    Hidden,
};

