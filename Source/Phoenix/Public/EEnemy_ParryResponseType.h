#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryResponseType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryResponseType : uint8 {
    Default,
    Massive,
    Heavy,
    Sustained,
    EEnemy_MAX UMETA(Hidden),
};

