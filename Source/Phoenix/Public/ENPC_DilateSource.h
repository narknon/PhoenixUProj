#pragma once
#include "CoreMinimal.h"
#include "ENPC_DilateSource.generated.h"

UENUM(BlueprintType)
enum class ENPC_DilateSource : uint8 {
    None,
    Recovery,
    Param,
    Time,
    ENPC_MAX UMETA(Hidden),
};

