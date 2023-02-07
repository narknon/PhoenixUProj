#pragma once
#include "CoreMinimal.h"
#include "EAOEMultiFXState.generated.h"

UENUM(BlueprintType)
enum class EAOEMultiFXState : uint8 {
    Announce,
    Warning,
    Explode,
    Expired,
    AnnounceStart,
    AnnounceLoop,
    WarningStart,
    WarningLoop,
    Impact,
    ImpactStart,
    ImpactEnd,
};

