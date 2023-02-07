#pragma once
#include "CoreMinimal.h"
#include "EFXPostProcessingDuplicateAction.generated.h"

UENUM(BlueprintType)
enum class EFXPostProcessingDuplicateAction : uint8 {
    Abort,
    Replace,
    RunAnyway,
};

