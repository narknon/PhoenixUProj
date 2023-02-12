#pragma once
#include "CoreMinimal.h"
#include "EAkChannelMask.generated.h"

UENUM(BlueprintType)
enum class EAkChannelMask : uint8 {
    FrontLeft,
    FrontRight,
    FrontCenter,
    LowFrequency,
    BackLeft,
    BackRight,
    BackCenter = 0x8,
    SideLeft,
    SideRight,
    Top,
    HeightFrontLeft,
    HeightFrontCenter,
    HeightFrontRight,
    HeightBackLeft,
    HeightBackCenter,
    HeightBackRight,
};

