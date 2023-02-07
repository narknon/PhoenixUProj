#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModParamType.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModParamType : uint8 {
    NoType,
    FloatType,
    BoolType,
    ColorType,
    LinearColorType,
    VectorType,
    TextureType,
};

