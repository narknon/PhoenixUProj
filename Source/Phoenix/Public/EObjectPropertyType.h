#pragma once
#include "CoreMinimal.h"
#include "EObjectPropertyType.generated.h"

UENUM(BlueprintType)
enum class EObjectPropertyType : uint8 {
    Animate,
    Inanimate,
    Plant,
    Dead,
    Water,
};

