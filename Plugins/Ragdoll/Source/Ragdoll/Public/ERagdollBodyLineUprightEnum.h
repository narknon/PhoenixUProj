#pragma once
#include "CoreMinimal.h"
#include "ERagdollBodyLineUprightEnum.generated.h"

UENUM(BlueprintType)
enum class ERagdollBodyLineUprightEnum : uint8 {
    RBLUE_SpineLineUpright,
    RBLUE_ShoulderLineUpright,
    RBLUE_HipLineUpright,
    RBLUE_ChestUpright,
    RBLUE_PelvisUpright,
    RBLUE_MAX UMETA(Hidden),
};

