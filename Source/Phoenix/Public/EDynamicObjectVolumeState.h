#pragma once
#include "CoreMinimal.h"
#include "EDynamicObjectVolumeState.generated.h"

UENUM(BlueprintType)
enum class EDynamicObjectVolumeState : uint8 {
    Inactive,
    Active,
};

