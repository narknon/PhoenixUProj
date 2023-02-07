#pragma once
#include "CoreMinimal.h"
#include "EContainerSelectionType.generated.h"

UENUM(BlueprintType)
enum class EContainerSelectionType : uint8 {
    RandomByWeight,
    InOrderByWeight,
};

