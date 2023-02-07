#pragma once
#include "CoreMinimal.h"
#include "ELinkType.generated.h"

UENUM(BlueprintType)
enum class ELinkType : uint8 {
    JUMP_LINK,
    LADDER_LINK,
    CLIMB_LINK,
    SLIDE_LINK,
    VAULT_LINK,
    SPLINE_LINK,
};

