#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAbilityTargetingFilter.generated.h"

UCLASS(Abstract, Blueprintable)
class ABLECORE_API UAblAbilityTargetingFilter : public UObject {
    GENERATED_BODY()
public:
    UAblAbilityTargetingFilter();
};

