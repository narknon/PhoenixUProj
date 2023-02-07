#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskSceneRigSetting.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskSceneRigSetting : uint8 {
    Play,
    Stop,
    Persistent,
};

