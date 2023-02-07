#pragma once
#include "CoreMinimal.h"
#include "EStationSnapConnectionsToGround.generated.h"

UENUM(BlueprintType)
enum EStationSnapConnectionsToGround {
    SCTG_UNKNOWN,
    SCTG_NO,
    SCTG_YES,
    SCTG_MAX UMETA(Hidden),
};

