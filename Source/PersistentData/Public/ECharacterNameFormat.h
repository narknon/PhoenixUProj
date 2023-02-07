#pragma once
#include "CoreMinimal.h"
#include "ECharacterNameFormat.generated.h"

UENUM(BlueprintType)
enum class ECharacterNameFormat : uint8 {
    NONE,
    ANSI,
    WIDE,
};

