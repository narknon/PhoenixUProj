#pragma once
#include "CoreMinimal.h"
#include "ENoMountZoneVersion.generated.h"

UENUM(BlueprintType)
enum class ENoMountZoneVersion : uint8 {
    NoVersion,
    UniqueNameFix,
    GroundShieldVFX,
    LatestVersion = 0x2,
};

