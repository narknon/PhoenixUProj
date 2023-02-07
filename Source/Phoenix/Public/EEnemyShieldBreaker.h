#pragma once
#include "CoreMinimal.h"
#include "EEnemyShieldBreaker.generated.h"

UENUM(BlueprintType)
enum class EEnemyShieldBreaker : uint8 {
    None,
    TypeA_Breaker,
    TypeB_Breaker,
    TypeC_Breaker,
};

