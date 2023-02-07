#pragma once
#include "CoreMinimal.h"
#include "EConjurationSpawnState.generated.h"

UENUM(BlueprintType)
enum class EConjurationSpawnState : uint8 {
    None,
    Spawned,
    SpawnIn,
    SpawnOut,
};

