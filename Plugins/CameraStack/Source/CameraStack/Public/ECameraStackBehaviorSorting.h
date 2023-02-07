#pragma once
#include "CoreMinimal.h"
#include "ECameraStackBehaviorSorting.generated.h"

UENUM(BlueprintType)
enum class ECameraStackBehaviorSorting : uint8 {
    Oldest,
    Newest,
    Bottommost,
    Topmost,
};

