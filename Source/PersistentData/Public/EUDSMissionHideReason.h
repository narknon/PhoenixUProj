#pragma once
#include "CoreMinimal.h"
#include "EUDSMissionHideReason.generated.h"

UENUM(BlueprintType)
enum class EUDSMissionHideReason : uint8 {
    MISSION_PREREQ_GATED,
    EXCLUSIVE_MISSION_GATED,
};

