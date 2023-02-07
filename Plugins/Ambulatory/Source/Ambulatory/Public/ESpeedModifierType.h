#pragma once
#include "CoreMinimal.h"
#include "ESpeedModifierType.generated.h"

UENUM(BlueprintType)
namespace ESpeedModifierType {
    enum Type {
        None,
        SprintFromButton,
        SprintFromKeyboard,
    };
}

