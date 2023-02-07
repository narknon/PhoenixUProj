#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsRegionChangeOp.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightGroupsRegionChangeOp : uint8 {
    Add,
    AddForceRefresh,
    Removed,
};

