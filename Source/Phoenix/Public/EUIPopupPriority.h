#pragma once
#include "CoreMinimal.h"
#include "EUIPopupPriority.generated.h"

UENUM(BlueprintType)
enum class EUIPopupPriority : uint8 {
    UIPP_Normal,
    UIPP_Important,
    UIPP_Critical,
    UIPP_MAX UMETA(Hidden),
};

