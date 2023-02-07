#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryClosure.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryClosure : uint8 {
    None,
    Success,
    Fail,
    Neutral,
    EEnemy_MAX UMETA(Hidden),
};

