#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryDodgeStyle.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryDodgeStyle : uint8 {
    RollAway,
    RollPerpendicular,
    RollTowards,
    DodgeAway,
    DodgePerpendicular,
    DodgeTowards,
    EEnemy_MAX UMETA(Hidden),
};

