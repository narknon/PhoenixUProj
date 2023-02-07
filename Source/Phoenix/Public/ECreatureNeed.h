#pragma once
#include "CoreMinimal.h"
#include "ECreatureNeed.generated.h"

UENUM(BlueprintType)
enum class ECreatureNeed : uint8 {
    Fed,
    InteractedWith,
    Count,
};

