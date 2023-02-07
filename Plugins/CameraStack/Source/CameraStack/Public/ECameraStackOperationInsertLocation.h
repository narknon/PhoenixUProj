#pragma once
#include "CoreMinimal.h"
#include "ECameraStackOperationInsertLocation.generated.h"

UENUM(BlueprintType)
enum class ECameraStackOperationInsertLocation : uint8 {
    TopOfStack,
    TopOfBaseStack,
    BeforeBehavior,
    AfterBehavior,
};

