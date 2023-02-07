#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackProgreesionType.generated.h"

UENUM(BlueprintType)
enum class Enemy_AttackProgreesionType : uint8 {
    None,
    Stupefy,
    Count,
    Enemy_MAX UMETA(Hidden),
};

