#pragma once
#include "CoreMinimal.h"
#include "ELerpVolumesGetTagValueMode.generated.h"

UENUM(BlueprintType)
enum class ELerpVolumesGetTagValueMode : uint8 {
    Default,
    FinalValue,
    FullList,
};

