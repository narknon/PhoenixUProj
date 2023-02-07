#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackSearchDistType.generated.h"

UENUM(BlueprintType)
enum class Enemy_AttackSearchDistType : uint8 {
    Average,
    Close,
    Far,
    Enemy_MAX UMETA(Hidden),
};

