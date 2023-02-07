#pragma once
#include "CoreMinimal.h"
#include "ERestoreFade.generated.h"

UENUM(BlueprintType)
enum class ERestoreFade : uint8 {
    Never,
    EndOfAction,
    EndOfSceneRig,
};

