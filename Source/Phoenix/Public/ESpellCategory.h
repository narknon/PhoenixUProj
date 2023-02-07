#pragma once
#include "CoreMinimal.h"
#include "ESpellCategory.generated.h"

UENUM(BlueprintType)
enum class ESpellCategory : uint8 {
    None,
    CC,
    Forceful,
    Heavy,
    Tool,
    Sanctuary,
    DarkArts,
};

