#pragma once
#include "CoreMinimal.h"
#include "EForceRenderSettingsScope.generated.h"

UENUM(BlueprintType)
enum class EForceRenderSettingsScope : uint8 {
    OnPlay,
    OnPlayCooked,
    OnPlayInEditor,
    OnEditorStartup,
    OnEndPlay,
    Always,
};

