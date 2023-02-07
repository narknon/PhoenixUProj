#pragma once
#include "CoreMinimal.h"
#include "EUserConsoleVariableBuilds.generated.h"

UENUM(BlueprintType)
enum class EUserConsoleVariableBuilds : uint8 {
    Editor,
    Debug,
    Development,
    Test,
    Shipping,
};

