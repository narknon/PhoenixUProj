#pragma once
#include "CoreMinimal.h"
#include "ETagOperation.generated.h"

UENUM(BlueprintType)
enum class ETagOperation : uint8 {
    Add,
    Remove,
};

