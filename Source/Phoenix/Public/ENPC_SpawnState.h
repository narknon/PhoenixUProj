#pragma once
#include "CoreMinimal.h"
#include "ENPC_SpawnState.generated.h"

UENUM(BlueprintType)
enum class ENPC_SpawnState : uint8 {
    None,
    Spawning,
    SpawnFinshed,
    ENPC_MAX UMETA(Hidden),
};

