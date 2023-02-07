#pragma once
#include "CoreMinimal.h"
#include "EMountTransitionAnimState.generated.h"

UENUM(BlueprintType)
enum class EMountTransitionAnimState : uint8 {
    Wait,
    Mount_Start,
    Mount_Cancel,
    Mount_Standing,
    Mount_Trot,
    Dismount_Standing_Start,
    Dismount_Trot_Start,
    Dismount_Standing,
    Dismount_Trot,
    Dismount_End,
    Dismount_Knockdown,
};

