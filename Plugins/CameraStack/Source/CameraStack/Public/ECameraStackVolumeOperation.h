#pragma once
#include "CoreMinimal.h"
#include "ECameraStackVolumeOperation.generated.h"

UENUM(BlueprintType)
enum class ECameraStackVolumeOperation : uint8 {
    AddOnTop,
    InsertBefore,
    InsertAfter,
    Replace,
};

