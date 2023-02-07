#pragma once
#include "CoreMinimal.h"
#include "ECharacterDynamicClothingType.generated.h"

UENUM(BlueprintType)
enum class ECharacterDynamicClothingType : uint8 {
    None,
    Tight,
    Loose,
    CapeOrRobe,
};

