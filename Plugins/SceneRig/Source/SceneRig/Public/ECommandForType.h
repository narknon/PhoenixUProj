#pragma once
#include "CoreMinimal.h"
#include "ECommandForType.generated.h"

UENUM(BlueprintType)
enum class ECommandForType : uint8 {
    Speaker,
    Listener,
    Both,
};

