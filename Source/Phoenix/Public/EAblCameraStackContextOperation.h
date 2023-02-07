#pragma once
#include "CoreMinimal.h"
#include "EAblCameraStackContextOperation.generated.h"

UENUM(BlueprintType)
enum class EAblCameraStackContextOperation : uint8 {
    Ignore,
    AddContext,
    RemoveContext,
};

