#pragma once
#include "CoreMinimal.h"
#include "EReticuleState.generated.h"

UENUM(BlueprintType)
enum class EReticuleState : uint8 {
    RS_Unlocked,
    RS_Locked,
    RS_FinisherActive,
    RS_FinisherFreeze,
    RS_Fire,
    RS_Idle,
    RS_MAX UMETA(Hidden),
};

