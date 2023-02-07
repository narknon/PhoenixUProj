#pragma once
#include "CoreMinimal.h"
#include "ETimeRig_StoryGraphEdgeInitType.generated.h"

UENUM(BlueprintType)
enum class ETimeRig_StoryGraphEdgeInitType : uint8 {
    InitializeWhenTriggered,
    InitializeWithPrevious,
    InitializeByEvent,
    DoNotInitialize,
    ETimeRig_MAX UMETA(Hidden),
};

