#pragma once
#include "CoreMinimal.h"
#include "ELeftArmState.generated.h"

UENUM(BlueprintType)
namespace ELeftArmState {
    enum Type {
        None,
        EquipItem,
        HoldItem,
        PlayExecuteMotion,
        PlayHandOnlyMotion,
        AllowMotionTakeover,
        StopMotionOnly,
        StopMotionAndHideItem,
        HideItem,
    };
}

