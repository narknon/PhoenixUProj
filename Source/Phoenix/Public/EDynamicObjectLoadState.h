#pragma once
#include "CoreMinimal.h"
#include "EDynamicObjectLoadState.generated.h"

UENUM(BlueprintType)
enum class EDynamicObjectLoadState : uint8 {
    None,
    Loading,
    Loaded,
    Unloaded,
    NotInRegistry,
    NotInAssetMap,
};

