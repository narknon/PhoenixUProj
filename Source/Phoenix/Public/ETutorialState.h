#pragma once
#include "CoreMinimal.h"
#include "ETutorialState.generated.h"

UENUM(BlueprintType)
enum class ETutorialState : uint8 {
    TS_Queued,
    TS_Loading,
    TS_Active,
    TS_MAX UMETA(Hidden),
};

