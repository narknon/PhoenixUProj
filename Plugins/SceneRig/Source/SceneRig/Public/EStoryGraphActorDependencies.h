#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphActorDependencies.generated.h"

UENUM(BlueprintType)
enum class EStoryGraphActorDependencies : uint8 {
    WaitingForCurtain = 0x1,
    WaitingForAmbient = 0x0,
};

