#pragma once
#include "CoreMinimal.h"
#include "EConsoleMacrosAutomationLevelType.generated.h"

UENUM(BlueprintType)
enum class EConsoleMacrosAutomationLevelType : uint8 {
    ExactMatch,
    PartialMatch,
};

