#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Ability.generated.h"

UENUM(BlueprintType)
enum class EEnemy_Ability : uint8 {
    Idle,
    Move,
    Attack,
    Dodge,
    Weapon_DEPRECATED,
    Shuffle,
    TurnInPlace,
    Taunt,
    MoveStop,
    BecomeAware,
    LoseAware,
    PickupWeapon,
    Apparate,
    Reaction,
    StoreWeapon,
    EquipWeapon,
    Spawn,
    Jump,
    Eat_DEPRECATED,
    Flee,
    Dead,
    NurtureInteract_DEPRECATED,
    MoveStart,
    GameEvent,
    Climb,
    Protego,
    SecondaryAttack,
    IdleBreak,
    BecomeAlert,
    LoseAlert,
    HealAttack,
    LosingTarget,
    PreAttack,
    Disillusionment,
    None,
    Lumos,
    Custom,
    ReparoAttack_Deprecated,
    Vault,
    MoveTransition,
    Flourish,
    Flying,
    FollowSpline,
    FollowSplineIdle,
    StartDrained,
    StopDrained,
    Drained,
    AlertWait,
    WanderIdle,
    AlertLook,
    AttackSplit,
    AlertFace,
    JumpSpline,
    MovePivot,
    AttackCounter,
    PreMoveStart,
    RecoverWeapon,
    InvestigateStart,
    InvestigateMove,
    InvestigateIdle,
    InvestigateStop,
    ChargeStart,
    Count,
    EEnemy_MAX UMETA(Hidden),
};

