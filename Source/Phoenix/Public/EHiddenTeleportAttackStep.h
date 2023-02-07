#pragma once
#include "CoreMinimal.h"
#include "EHiddenTeleportAttackStep.generated.h"

UENUM(BlueprintType)
enum class EHiddenTeleportAttackStep : uint8 {
    ChooseAttackLocation,
    Teleport,
    Hide,
};

