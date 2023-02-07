#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesObjectMatchMode.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapRulesObjectMatchMode : uint8 {
    Exact,
    SubStringCaseSensitve,
    SubStringIgnoreCase,
};

