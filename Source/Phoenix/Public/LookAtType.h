#pragma once
#include "CoreMinimal.h"
#include "LookAtType.generated.h"

UENUM(BlueprintType)
enum class LookAtType : uint8 {
    Player,
    SpellTarget,
    Both,
};

