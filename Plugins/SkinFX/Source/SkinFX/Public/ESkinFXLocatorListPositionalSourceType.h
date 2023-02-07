#pragma once
#include "CoreMinimal.h"
#include "ESkinFXLocatorListPositionalSourceType.generated.h"

UENUM(BlueprintType)
enum class ESkinFXLocatorListPositionalSourceType : uint8 {
    Bone,
    Socket,
    Impact,
};

