#pragma once
#include "CoreMinimal.h"
#include "PanningRule.generated.h"

UENUM(BlueprintType)
enum class PanningRule : uint8 {
    PanningRule_Speakers,
    PanningRule_Headphones,
};

