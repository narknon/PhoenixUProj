#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactChannelType.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactChannelType : uint8 {
    Fullbody,
    Additive,
    PartialBody,
};

