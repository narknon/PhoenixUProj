#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueRequirementFunction.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueRequirementFunction : uint8 {
    All,
    AnyOne,
    AnyTwo,
    FirstPlusAnyOne,
};

