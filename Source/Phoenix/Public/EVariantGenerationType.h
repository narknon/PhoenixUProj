#pragma once
#include "CoreMinimal.h"
#include "EVariantGenerationType.generated.h"

UENUM(BlueprintType)
enum class EVariantGenerationType : uint8 {
    NOTRAITS,
    FULLTRAITS,
    ONETRAIT,
};

