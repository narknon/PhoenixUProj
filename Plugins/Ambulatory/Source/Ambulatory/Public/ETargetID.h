#pragma once
#include "CoreMinimal.h"
#include "ETargetID.generated.h"

UENUM(BlueprintType)
namespace ETargetID {
    enum Type {
        None,
        LowestPriority,
        AimModeFace,
        LockOnTarget,
        FocusTriggerOpenWorld,
        FocusTriggerOtherNPC,
        FocusTriggerPlayer,
        FocusTriggerWorldEvent,
        LookAtDesiredDirection,
        LookAtInteractTargetsBlip,
        LookAtAutoTargets,
        LookAtInteractTargets,
        LookAtTargetsOfInterest,
        LookAtDanger,
        TargetOfInterest,
        TemporaryTarget,
        ImpactTarget,
        LootTarget,
        AimMode,
        ChannelSpell,
        ConjureSpell,
        ProtegoTarget,
        HighPriority,
        HighestPriority,
    };
}

