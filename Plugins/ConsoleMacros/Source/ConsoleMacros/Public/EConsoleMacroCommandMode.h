#pragma once
#include "CoreMinimal.h"
#include "EConsoleMacroCommandMode.generated.h"

UENUM(BlueprintType)
enum class EConsoleMacroCommandMode : uint8 {
    Execute,
    Restore,
    Query,
};

