#pragma once
#include "CoreMinimal.h"
#include "EInteractiveAction.generated.h"

UENUM(BlueprintType)
enum class EInteractiveAction : uint8 {
    None,
    Interact,
    Auto,
    Lock,
    Unlock,
    Freeze,
    Thaw,
    Wet,
    Dry,
    StartFire,
    ExtinguishFire,
    IncreaseScale,
    DecreaseScale,
    IncreaseScaleRestore,
    DecreaseScaleRestore,
    Highlight,
    Unhighlight,
    Invisible,
    Visible,
    Immobilized,
    Mobilized,
    Damage,
    Destroy,
    Cut,
    Repair,
    Stun,
    Grown,
};

