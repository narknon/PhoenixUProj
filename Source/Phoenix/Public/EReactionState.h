#pragma once
#include "CoreMinimal.h"
#include "EReactionState.generated.h"

UENUM(BlueprintType)
namespace EReactionState {
    enum Type {
        None,
        HitLegsLeft,
        HitLegsRight,
        DeathFront,
        DeathLeft,
        DeathRight,
        DeathBack,
        HitHeadDownFront,
        HitHeadDownLeft,
        HitHeadDownRight,
        HitHeadFront,
        HitHeadLeft,
        HitHeadRight,
        HitHeadUpFront,
        HitHeadUpLeft,
        HitHeadUpRight,
        HitTorsoFront,
        HitTorsoLeft,
        HitTorsoRight,
        KnockDownFront,
        KnockDownLeft,
        KnockDownRight,
    };
}

