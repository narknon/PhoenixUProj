#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsScalarConversion.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsScalarConversion : uint8 {
    None,
    EV100ToMultipler,
    MultiplierToEV100,
};

