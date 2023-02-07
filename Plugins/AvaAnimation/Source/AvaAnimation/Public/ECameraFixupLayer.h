#pragma once
#include "CoreMinimal.h"
#include "ECameraFixupLayer.generated.h"

UENUM(BlueprintType)
enum class ECameraFixupLayer : uint8 {
    Lowest,
    Passive,
    Active,
    Highest,
};

