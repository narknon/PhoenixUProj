#pragma once
#include "CoreMinimal.h"
#include "EMultiFXActor.generated.h"

UENUM(BlueprintType)
enum class EMultiFXActor : uint8 {
    Target,
    Instigator,
    Player,
};

