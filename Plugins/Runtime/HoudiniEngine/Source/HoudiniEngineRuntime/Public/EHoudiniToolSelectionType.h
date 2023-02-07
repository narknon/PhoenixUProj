#pragma once
#include "CoreMinimal.h"
#include "EHoudiniToolSelectionType.generated.h"

UENUM(BlueprintType)
enum class EHoudiniToolSelectionType : uint8 {
    HTOOL_SELECTION_ALL,
    HTOOL_SELECTION_WORLD_ONLY,
    HTOOL_SELECTION_CB_ONLY,
    HTOOL_SELECTION_MAX UMETA(Hidden),
};

