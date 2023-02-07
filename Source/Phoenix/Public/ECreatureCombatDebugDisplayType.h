#pragma once
#include "CoreMinimal.h"
#include "ECreatureCombatDebugDisplayType.generated.h"

UENUM(BlueprintType)
enum class ECreatureCombatDebugDisplayType : uint8 {
    None,
    WhenActive,
    Always,
};

