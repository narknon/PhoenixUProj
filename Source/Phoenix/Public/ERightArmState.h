#pragma once
#include "CoreMinimal.h"
#include "ERightArmState.generated.h"

UENUM(BlueprintType)
namespace ERightArmState {
    enum Type {
        None,
        EquipItem,
        UnEquipItem,
        HoldItem,
        PlayExecuteMotion,
        PlayHandOnlyMotion,
        AllowMotionTakeover,
        StopMotionOnly,
        StopMotionAndHideItem,
        HideItem,
        TargetSighted,
        PlayAlertedMotion,
        PlayHeavyAniticipationMotion,
        Optional_PlayHandOnlyMotion,
        StartLumos,
        Channeling,
        Transfiguration,
        WandCastFailed,
    };
}

