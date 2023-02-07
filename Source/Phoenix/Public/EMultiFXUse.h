#pragma once
#include "CoreMinimal.h"
#include "EMultiFXUse.generated.h"

UENUM(BlueprintType)
enum class EMultiFXUse : uint8 {
    Target,
    Instigator,
    TargetCharacter,
    InstigatorCharacter,
};

