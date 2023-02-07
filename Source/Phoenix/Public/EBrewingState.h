#pragma once
#include "CoreMinimal.h"
#include "EBrewingState.generated.h"

UENUM(BlueprintType)
enum class EBrewingState : uint8 {
    None,
    Brewing,
    Brewed,
};

