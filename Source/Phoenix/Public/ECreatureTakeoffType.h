#pragma once
#include "CoreMinimal.h"
#include "ECreatureTakeoffType.generated.h"

UENUM(BlueprintType)
enum class ECreatureTakeoffType : uint8 {
    None,
    Standing,
    Gallop,
};

