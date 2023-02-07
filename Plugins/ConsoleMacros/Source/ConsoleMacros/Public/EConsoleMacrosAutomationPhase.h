#pragma once
#include "CoreMinimal.h"
#include "EConsoleMacrosAutomationPhase.generated.h"

UENUM(BlueprintType)
enum class EConsoleMacrosAutomationPhase : uint8 {
    OnBeginPlay,
    OnEndPlay,
    OnBeginPlayInEditor,
    OnEndPlayInEditor,
    OnEditorLevelOpen,
    OnEditorLevelClose,
};

