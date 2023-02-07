#pragma once
#include "CoreMinimal.h"
#include "EObjectFadeCompletedAction.generated.h"

UENUM(BlueprintType)
enum class EObjectFadeCompletedAction : uint8 {
    Default,
    HoldInSystem,
    ReleaseFromSystem,
    FadeOut_HideObject,
    FadeOut_KillObject,
};

