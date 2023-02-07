#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_CreatureFlyingOption.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_CreatureFlyingOption : uint8 {
    StopFlying,
    StartFlying,
    ESceneAction_MAX UMETA(Hidden),
};

