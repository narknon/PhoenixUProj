#pragma once
#include "CoreMinimal.h"
#include "EFT_TriggerType.generated.h"

UENUM(BlueprintType)
enum class EFT_TriggerType : uint8 {
    All,
    SceneRig,
    StoryGraph,
    EFT_MAX UMETA(Hidden),
};

