#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapInfoTyoe.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapInfoTyoe : uint8 {
    UseMaterialPermuter,
    InPlaceMIDs,
    MaterialOverride,
    MaterialOverrides,
};

