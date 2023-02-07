#pragma once
#include "CoreMinimal.h"
#include "Enemy_MorphStatus.generated.h"

UENUM(BlueprintType)
enum class Enemy_MorphStatus : uint8 {
    None,
    MorphingToWolf,
    MorphingToMage,
    Enemy_MAX UMETA(Hidden),
};

