#pragma once
#include "CoreMinimal.h"
#include "EMoonPathMode.generated.h"

UENUM(BlueprintType)
enum class EMoonPathMode : uint8 {
    SunRelative,
    MoonRelative,
    Absolute,
};

