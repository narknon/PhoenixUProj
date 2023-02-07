#pragma once
#include "CoreMinimal.h"
#include "EPrerequisiteType.generated.h"

UENUM(BlueprintType)
enum class EPrerequisiteType : uint8 {
    None,
    Disable_On_MissionStatus,
    Enable_On_MissionStatus,
    Disable_On_ProgressionLock,
    Enable_On_ProgressionLock,
};

