#pragma once
#include "CoreMinimal.h"
#include "EStationSelectionMethod.generated.h"

UENUM(BlueprintType)
enum EStationSelectionMethod {
    EQS_SELECT_CLOSEST,
    EQS_SELECT_FARTHEST,
    EQS_SELECT_RANDOM,
    EQS_SELECT_ALL,
    EQS_SELECT_MAX UMETA(Hidden),
};

