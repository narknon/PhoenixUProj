#pragma once
#include "CoreMinimal.h"
#include "ESpiderTypeEnum.generated.h"

UENUM(BlueprintType)
enum class ESpiderTypeEnum : uint8 {
    ST_Woodlouse,
    ST_Venomous,
    ST_Luminous,
    ST_MAX UMETA(Hidden),
};

