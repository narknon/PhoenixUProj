#pragma once
#include "CoreMinimal.h"
#include "ETutorialTransparency.generated.h"

UENUM(BlueprintType)
enum class ETutorialTransparency : uint8 {
    Tutorial_Transparency_Translucent,
    Tutorial_Transparency_Opaque,
    Tutorial_Transparency_MAX UMETA(Hidden),
};

