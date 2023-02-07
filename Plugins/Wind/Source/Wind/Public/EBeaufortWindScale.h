#pragma once
#include "CoreMinimal.h"
#include "EBeaufortWindScale.generated.h"

UENUM(BlueprintType)
enum class EBeaufortWindScale : uint8 {
    Calm,
    LightAir,
    LightBreeze,
    GentleBreeze,
    ModerateBreeze,
    FreshBreeze,
    StrongBreeze,
    ModerateGale,
    FreshGale,
    StrongGale,
    WholeGale,
    Storm,
    Hurricane,
};

