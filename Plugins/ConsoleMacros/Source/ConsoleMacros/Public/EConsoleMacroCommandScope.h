#pragma once
#include "CoreMinimal.h"
#include "EConsoleMacroCommandScope.generated.h"

UENUM(BlueprintType)
enum class EConsoleMacroCommandScope : uint8 {
    CookedAndEditor,
    CookedOnly,
    EditorOnly,
};

