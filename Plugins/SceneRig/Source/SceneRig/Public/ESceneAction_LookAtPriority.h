#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_LookAtPriority.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_LookAtPriority : uint8 {
    Lowest,
    Passive,
    Active,
    Highest,
    ESceneAction_MAX UMETA(Hidden),
};

