#pragma once
#include "CoreMinimal.h"
#include "EDebugPanelControlID.generated.h"

UENUM(BlueprintType)
enum class EDebugPanelControlID : uint8 {
    EDPCID_TEXT_LEFT,
    EDPCID_TEXT_TOP,
    EDPCID_TEXT_RIGHT,
    EDPCID_TEXT_BOTTOM,
    EDPCID_TEXT_MAX UMETA(Hidden),
};

