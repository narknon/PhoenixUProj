#pragma once
#include "CoreMinimal.h"
#include "UIActionModes.generated.h"

UENUM(BlueprintType)
enum UIActionModes {
    UI_ACTIONMODE_ADVENTURE,
    UI_ACTIONMODE_SANCTUARY,
    UI_ACTIONMODE_COUNT,
    UI_ACTIONMODE_MAX UMETA(Hidden),
};

