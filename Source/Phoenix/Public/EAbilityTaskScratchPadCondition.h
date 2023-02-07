#pragma once
#include "CoreMinimal.h"
#include "EAbilityTaskScratchPadCondition.generated.h"

UENUM(BlueprintType)
enum class EAbilityTaskScratchPadCondition : uint8 {
    None,
    Hit,
    HitTarget,
    HitGround,
    IsBurning,
    IsCharred,
    HasTarget,
    IsDead,
    TriggerTransition,
    RandomDuration,
    RandomDurationTransition,
    ApparateAttackCount,
    HideLocSelected,
    JumpSplineDone,
    SplineSpawnAdvance,
    Suspended,
    Hovering,
    HasWeapon,
    AttackCustomFlag,
    TasIsAlert,
    TasIsAttack,
    IsSwimming,
};

