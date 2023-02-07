#pragma once
#include "CoreMinimal.h"
#include "EAblAddLinearImpulseDirectionType.generated.h"

UENUM(BlueprintType)
enum class EAblAddLinearImpulseDirectionType : uint8 {
    Global,
    Local,
    ImpactDirection,
};

