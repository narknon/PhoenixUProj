#pragma once
#include "CoreMinimal.h"
#include "ETutorialPersistence.generated.h"

UENUM(BlueprintType)
enum class ETutorialPersistence : uint8 {
    Tutorial_Persistence_Restart,
    Tutorial_Persistence_Ignore,
    Tutorial_Persistence_MAX UMETA(Hidden),
};

