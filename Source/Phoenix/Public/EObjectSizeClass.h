#pragma once
#include "CoreMinimal.h"
#include "EObjectSizeClass.generated.h"

UENUM(BlueprintType)
enum class EObjectSizeClass : uint8 {
    XXS,
    XS,
    S,
    M,
    L,
    XL,
    XXL,
    AutoGenerate,
};

