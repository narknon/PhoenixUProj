#pragma once
#include "CoreMinimal.h"
#include "ESurfaceFogType.generated.h"

UENUM(BlueprintType)
enum class ESurfaceFogType : uint8 {
    None,
    Mist,
    Fog,
    Storm,
};

