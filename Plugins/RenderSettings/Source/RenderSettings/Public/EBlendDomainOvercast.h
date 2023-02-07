#pragma once
#include "CoreMinimal.h"
#include "EBlendDomainOvercast.generated.h"

UENUM(BlueprintType)
enum class EBlendDomainOvercast : uint8 {
    ClearAndOvercast,
    ClearOnly,
    OvercastOnly,
};

