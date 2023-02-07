#pragma once
#include "CoreMinimal.h"
#include "EHoudiniToolType.generated.h"

UENUM(BlueprintType)
enum class EHoudiniToolType : uint8 {
    HTOOLTYPE_GENERATOR,
    HTOOLTYPE_OPERATOR_SINGLE,
    HTOOLTYPE_OPERATOR_MULTI,
    HTOOLTYPE_OPERATOR_BATCH,
    HTOOLTYPE_MAX UMETA(Hidden),
};

