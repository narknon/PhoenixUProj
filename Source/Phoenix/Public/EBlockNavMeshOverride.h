#pragma once
#include "CoreMinimal.h"
#include "EBlockNavMeshOverride.generated.h"

UENUM(BlueprintType)
enum class EBlockNavMeshOverride : uint8 {
    AllowOverride,
    UseValueAsIs,
};

