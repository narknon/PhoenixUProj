#pragma once
#include "CoreMinimal.h"
#include "EObjectFadeMasterState.generated.h"

UENUM(BlueprintType)
enum class EObjectFadeMasterState : uint8 {
    NotFound,
    FadingIn,
    FadingOut,
};

