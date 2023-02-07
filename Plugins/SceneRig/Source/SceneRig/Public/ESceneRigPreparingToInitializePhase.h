#pragma once
#include "CoreMinimal.h"
#include "ESceneRigPreparingToInitializePhase.generated.h"

UENUM(BlueprintType)
enum class ESceneRigPreparingToInitializePhase : uint8 {
    Uninitialized,
    WorldTransitioning,
    RequestingRequiredLevels,
    LoadingRequiredLevels,
    WaitingToCompleteStreaming,
    PreparedToInitialize,
};

