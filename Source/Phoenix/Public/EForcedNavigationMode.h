#pragma once
#include "CoreMinimal.h"
#include "EForcedNavigationMode.generated.h"

UENUM(BlueprintType)
enum class EForcedNavigationMode : uint8 {
    None,
    FreezeNavigation,
    AsyncPathNavigation,
};

