#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskFinishAction.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskFinishAction : uint8 {
    ReturnToActivity,
    StopAndWait,
    ContinueTaskWhenCancelled,
};

