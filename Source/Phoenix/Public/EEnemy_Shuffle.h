#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Shuffle.generated.h"

UENUM(BlueprintType)
enum class EEnemy_Shuffle : uint8 {
    Forward,
    Left45,
    Left90,
    Left135,
    Back,
    Right135,
    Right90,
    Right45,
    EEnemy_MAX UMETA(Hidden),
};

