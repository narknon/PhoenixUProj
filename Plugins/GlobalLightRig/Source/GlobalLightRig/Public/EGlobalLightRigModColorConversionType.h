#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModColorConversionType.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModColorConversionType : uint8 {
    None,
    ColorTemperatureK,
    BlackBodyK,
    Saturation,
    Brightness,
};

