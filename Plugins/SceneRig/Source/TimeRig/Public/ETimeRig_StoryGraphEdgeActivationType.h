#pragma once
#include "CoreMinimal.h"
#include "ETimeRig_StoryGraphEdgeActivationType.generated.h"

UENUM(BlueprintType)
enum class ETimeRig_StoryGraphEdgeActivationType : uint8 {
    ActivatedByFinish,
    ActivatedByEvent,
    DoNotActivate,
    ETimeRig_MAX UMETA(Hidden),
};

