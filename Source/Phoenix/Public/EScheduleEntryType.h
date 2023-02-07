#pragma once
#include "CoreMinimal.h"
#include "EScheduleEntryType.generated.h"

UENUM(BlueprintType)
enum class EScheduleEntryType : uint8 {
    type_static,
    type_dynamic,
    type_MAX UMETA(Hidden),
};

