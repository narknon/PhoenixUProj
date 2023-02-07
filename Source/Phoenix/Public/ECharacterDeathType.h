#pragma once
#include "CoreMinimal.h"
#include "ECharacterDeathType.generated.h"

UENUM(BlueprintType)
enum class ECharacterDeathType : uint8 {
    Default,
    SplatteringHighFallDeath,
    Spell,
    Custom,
};

