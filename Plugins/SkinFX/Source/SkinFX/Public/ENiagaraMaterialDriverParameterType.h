#pragma once
#include "CoreMinimal.h"
#include "ENiagaraMaterialDriverParameterType.generated.h"

UENUM(BlueprintType)
enum class ENiagaraMaterialDriverParameterType : uint8 {
    Scalar,
    Vector2,
    Vector,
    Vector4,
    LinearColor,
    Quaternion,
    QuaternionForward,
    QuaternionUp,
    QuaternionRight,
    UniformScale,
    RelativePosition,
    DirectionTo,
};

