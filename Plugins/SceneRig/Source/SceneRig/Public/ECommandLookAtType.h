#pragma once
#include "CoreMinimal.h"
#include "ECommandLookAtType.generated.h"

UENUM(BlueprintType)
enum class ECommandLookAtType : uint8 {
    Speaker,
    Listener,
};

