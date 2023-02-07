#pragma once
#include "CoreMinimal.h"
#include "ECreatorUpdateState.generated.h"

UENUM(BlueprintType)
enum class ECreatorUpdateState : uint8 {
    UpdateSuccess,
    UpdateFail,
    UpdateCurrent,
    UpdateDBFail,
};

