#pragma once
#include "CoreMinimal.h"
#include "ETrollSwingDirection.generated.h"

UENUM(BlueprintType)
enum class ETrollSwingDirection : uint8 {
    Forehand,
    Backhand,
    None,
};

