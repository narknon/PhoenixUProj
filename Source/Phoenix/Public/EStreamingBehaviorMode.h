#pragma once
#include "CoreMinimal.h"
#include "EStreamingBehaviorMode.generated.h"

UENUM(BlueprintType)
enum class EStreamingBehaviorMode : uint8 {
    Loading,
    Flight,
    Gameplay,
};

