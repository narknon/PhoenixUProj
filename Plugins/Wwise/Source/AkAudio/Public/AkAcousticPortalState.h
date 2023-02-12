#pragma once
#include "CoreMinimal.h"
#include "AkAcousticPortalState.generated.h"

UENUM(BlueprintType)
enum class AkAcousticPortalState : uint8 {
    Closed,
    Open,
};

