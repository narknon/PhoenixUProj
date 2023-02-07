#pragma once
#include "CoreMinimal.h"
#include "ECombatParryType.generated.h"

UENUM(BlueprintType)
enum class ECombatParryType : uint8 {
    CPT_Parry,
    CPT_Dodge,
    CPT_MAX UMETA(Hidden),
};

