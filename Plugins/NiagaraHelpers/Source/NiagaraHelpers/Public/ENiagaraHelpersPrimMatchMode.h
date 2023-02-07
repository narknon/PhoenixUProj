#pragma once
#include "CoreMinimal.h"
#include "ENiagaraHelpersPrimMatchMode.generated.h"

UENUM(BlueprintType)
enum class ENiagaraHelpersPrimMatchMode : uint8 {
    Exact,
    SubStringCaseSensitve,
    SubStringIgnoreCase,
};

