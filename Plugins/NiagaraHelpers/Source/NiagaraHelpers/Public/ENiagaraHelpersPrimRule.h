#pragma once
#include "CoreMinimal.h"
#include "ENiagaraHelpersPrimRule.generated.h"

UENUM(BlueprintType)
enum class ENiagaraHelpersPrimRule : uint8 {
    DoNotSpawn,
    OnlySpawn,
};

