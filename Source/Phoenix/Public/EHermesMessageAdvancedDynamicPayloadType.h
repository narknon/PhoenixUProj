#pragma once
#include "CoreMinimal.h"
#include "EHermesMessageAdvancedDynamicPayloadType.generated.h"

UENUM(BlueprintType)
enum class EHermesMessageAdvancedDynamicPayloadType : uint8 {
    None,
    Name,
    Boolean,
    Integer,
    Scalar,
};

