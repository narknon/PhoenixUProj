#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityTaskRealm.generated.h"

UENUM(BlueprintType)
enum class EAblAbilityTaskRealm : uint8 {
    Client,
    Server,
    ClientAndServer,
    TotalRealms,
};

