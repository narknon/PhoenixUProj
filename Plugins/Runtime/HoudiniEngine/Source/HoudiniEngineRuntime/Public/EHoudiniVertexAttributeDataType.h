#pragma once
#include "CoreMinimal.h"
#include "EHoudiniVertexAttributeDataType.generated.h"

UENUM(BlueprintType)
enum EHoudiniVertexAttributeDataType {
    VADT_Float,
    VADT_Int32,
    VADT_Bool,
    VADT_MAX UMETA(Hidden),
};

