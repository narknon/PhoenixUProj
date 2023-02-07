#pragma once
#include "CoreMinimal.h"
#include "ECharacterDynamicClothingTypes.generated.h"

UENUM(BlueprintType)
enum class ECharacterDynamicClothingTypes : uint8 {
    Tight,
    Loose,
    CapeOrRobe,
};

