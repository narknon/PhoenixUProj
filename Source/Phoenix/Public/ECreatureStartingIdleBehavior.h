#pragma once
#include "CoreMinimal.h"
#include "ECreatureStartingIdleBehavior.generated.h"

UENUM(BlueprintType)
enum class ECreatureStartingIdleBehavior : uint8 {
    Explore,
    Forage,
    Rest,
};

