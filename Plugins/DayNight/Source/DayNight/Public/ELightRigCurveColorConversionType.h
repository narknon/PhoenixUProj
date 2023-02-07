#pragma once
#include "CoreMinimal.h"
#include "ELightRigCurveColorConversionType.generated.h"

UENUM(BlueprintType)
enum class ELightRigCurveColorConversionType : uint8 {
    None,
    ColorTemperatureK,
    BlackBodyK,
    Saturation,
    Brightness,
};

