#pragma once
#include "CoreMinimal.h"
#include "ESexType.generated.h"

UENUM(BlueprintType)
enum class ESexType : uint8 {
    type_male,
    type_female,
    type_MAX UMETA(Hidden),
};

