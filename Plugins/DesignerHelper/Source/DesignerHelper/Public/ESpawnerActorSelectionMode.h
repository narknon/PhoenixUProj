#pragma once
#include "CoreMinimal.h"
#include "ESpawnerActorSelectionMode.generated.h"

UENUM(BlueprintType)
enum class ESpawnerActorSelectionMode : uint8 {
    Undefined,
    FirstClass,
    MultipleClass,
    RandomClass,
};

