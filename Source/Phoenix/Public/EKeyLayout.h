#pragma once
#include "CoreMinimal.h"
#include "EKeyLayout.generated.h"

UENUM(BlueprintType)
enum class EKeyLayout : uint8 {
    QWERTY,
    QWERTZ,
    AZERTY,
    QWERTY_AZERTY,
};

