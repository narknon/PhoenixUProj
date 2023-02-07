#pragma once
#include "CoreMinimal.h"
#include "EMissionTabType.generated.h"

UENUM(BlueprintType)
enum class EMissionTabType : uint8 {
    TABTYPE_ALL,
    TABTYPE_MAIN,
    TABTYPE_SIDE,
    TABTYPE_ASSIGNMENT,
    TABTYPE_RELATIONSHIP,
    TABTYPE_COMPLETE,
    TABTYPE_MAX UMETA(Hidden),
};

