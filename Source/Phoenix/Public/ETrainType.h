#pragma once
#include "CoreMinimal.h"
#include "ETrainType.generated.h"

UENUM(BlueprintType)
enum class ETrainType : uint8 {
    TRAIN_ENGINE,
    TRAIN_COAL,
    TRAIN_CARRIAGE,
    MAX,
};

