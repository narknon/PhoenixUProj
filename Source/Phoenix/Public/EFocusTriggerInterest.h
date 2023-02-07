#pragma once
#include "CoreMinimal.h"
#include "EFocusTriggerInterest.generated.h"

UENUM(BlueprintType)
enum EFocusTriggerInterest {
    FOCUSTRIGGER_INTEREST_LOOK,
    FOCUSTRIGGER_INTEREST_ACTION,
    FOCUSTRIGGER_INTEREST_COUNT,
    FOCUSTRIGGER_INTEREST_MAX UMETA(Hidden),
};

