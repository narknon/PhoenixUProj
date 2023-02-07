#pragma once
#include "CoreMinimal.h"
#include "ETimeRigExternalEventConstraint.generated.h"

UENUM(BlueprintType)
enum class ETimeRigExternalEventConstraint : uint8 {
    NotConstrained,
    BeforeEvent,
    AfterEvent,
};

