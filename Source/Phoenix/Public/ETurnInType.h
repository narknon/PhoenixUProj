#pragma once
#include "CoreMinimal.h"
#include "ETurnInType.generated.h"

UENUM(BlueprintType)
enum class ETurnInType : uint8 {
    None,
    Item,
    Knowledge,
    Lock,
};

