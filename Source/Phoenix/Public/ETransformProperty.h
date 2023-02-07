#pragma once
#include "CoreMinimal.h"
#include "ETransformProperty.generated.h"

UENUM(BlueprintType)
enum class ETransformProperty : uint8 {
    TP_Translation,
    TP_Scale,
    TP_Shear,
    TP_Angle,
    TP_MAX UMETA(Hidden),
};

