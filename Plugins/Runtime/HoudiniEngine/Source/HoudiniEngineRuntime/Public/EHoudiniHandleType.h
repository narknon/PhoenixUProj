#pragma once
#include "CoreMinimal.h"
#include "EHoudiniHandleType.generated.h"

UENUM(BlueprintType)
enum class EHoudiniHandleType : uint8 {
    Xform,
    Bounder,
    Unsupported,
};

