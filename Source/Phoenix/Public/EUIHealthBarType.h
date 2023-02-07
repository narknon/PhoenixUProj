#pragma once
#include "CoreMinimal.h"
#include "EUIHealthBarType.generated.h"

UENUM(BlueprintType)
enum class EUIHealthBarType : uint8 {
    HBT_Normal,
    HBT_Boss,
    HBT_Named,
    HBT_Student,
    HBT_None,
    HBT_Count,
    HBT_MAX UMETA(Hidden),
};

