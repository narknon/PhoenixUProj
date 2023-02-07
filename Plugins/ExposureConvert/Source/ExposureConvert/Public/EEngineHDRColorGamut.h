#pragma once
#include "CoreMinimal.h"
#include "EEngineHDRColorGamut.generated.h"

UENUM(BlueprintType)
enum class EEngineHDRColorGamut : uint8 {
    Rec709_sRGB,
    DCI_P3,
    Rec2020_BT2020,
    ACES,
    ACEScg,
};

