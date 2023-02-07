#pragma once
#include "CoreMinimal.h"
#include "EWandCastCommand.generated.h"

UENUM(BlueprintType)
namespace EWandCastCommand {
    enum Type {
        None,
        FromDodgeDirectional,
        MeleeDirectional,
        LightDirectional,
        LightDirectionalTooClose,
        HeavyDirectional,
        SpecificTag,
        SpecificTagTooClose,
        StealthDirectional,
    };
}

