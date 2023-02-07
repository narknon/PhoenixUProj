#pragma once
#include "CoreMinimal.h"
#include "ERPGEffect.generated.h"

UENUM(BlueprintType)
enum class ERPGEffect : uint8 {
    None,
    Damage_CriticalHit,
    Potions_DoubleEffective,
};

