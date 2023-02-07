#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ContextMatch.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ContextMatch : uint8 {
    Any,
    All,
    EEnemy_MAX UMETA(Hidden),
};

