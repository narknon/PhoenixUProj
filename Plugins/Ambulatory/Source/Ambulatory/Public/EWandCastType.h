#pragma once
#include "CoreMinimal.h"
#include "EWandCastType.generated.h"

UENUM(BlueprintType)
namespace EWandCastType {
    enum Type {
        None,
        LightAttack,
        HeavyAttack,
        MeleeAttack,
        ComboFinisherAttack,
    };
}

