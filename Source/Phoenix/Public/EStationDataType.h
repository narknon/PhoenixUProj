#pragma once
#include "CoreMinimal.h"
#include "EStationDataType.generated.h"

UENUM(BlueprintType)
enum EStationDataType {
    TYPE_OWNED,
    TYPE_MANAGED,
    TYPE_SITE,
    TYPE_SPAWNED,
    TYPE_PLAYER,
    TYPE_PORTAL,
    TYPE_FLUID,
    TYPE_MAX UMETA(Hidden),
};

