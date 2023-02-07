#pragma once
#include "CoreMinimal.h"
#include "ETransfigurationActionFlags.generated.h"

UENUM(BlueprintType)
enum class ETransfigurationActionFlags : uint8 {
    DUMMY,
    Conjuration,
    Transformation,
    Levitation = 0x4,
    Vanishment = 0x8,
    Colovaria = 0x10,
    Scaling = 0x20,
    Rotation = 0x40,
};

