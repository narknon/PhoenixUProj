#pragma once
#include "CoreMinimal.h"
#include "EAblNPCTurnToTaskDestination.generated.h"

UENUM(BlueprintType)
enum class EAblNPCTurnToTaskDestination : uint8 {
    Self,
    Owner,
    Instigator,
    TargetActor,
    Camera,
    NpcReactionImpactDirection,
    AlignToParent,
    NpcReactionTargetActor,
    NpcReactionTargetLocation,
    ImpactDirectionFwdBwd,
    ImpactDirectionFwdBwdLftRgt,
    ImpactDirectionFwdBwdInv,
    NpcReactVelDir,
    NpcReactVelDirInv,
    JumpLanding,
    EnemyTarget,
};

