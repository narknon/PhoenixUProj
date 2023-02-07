#pragma once
#include "CoreMinimal.h"
#include "EMapZoomTypes.generated.h"

UENUM(BlueprintType)
namespace EMapZoomTypes {
    enum Type {
        MAP_TOOL_TIP_TYPE_INVALID,
        MAP_TOOL_TIP_TYPE_TIER1,
        MAP_TOOL_TIP_TYPE_TIER2,
        MAP_TOOL_TIP_TYPE_TIER3,
        MAP_TOOL_TIP_TYPE_TIER4,
        MAP_TOOL_TIP_TYPE_TIER5,
        MAP_TOOL_TIP_TYPE_MAX UMETA(Hidden),
    };
}

