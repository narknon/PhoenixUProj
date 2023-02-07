#pragma once
#include "CoreMinimal.h"
#include "EAblTargetingFilterSort.generated.h"

UENUM(BlueprintType)
enum EAblTargetingFilterSort {
    AblTargetFilterSort_Ascending,
    AblTargetFilterSort_Descending,
    AblTargetFilterSort_MAX UMETA(Hidden),
};

