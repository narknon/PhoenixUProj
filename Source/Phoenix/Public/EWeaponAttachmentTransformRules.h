#pragma once
#include "CoreMinimal.h"
#include "EWeaponAttachmentTransformRules.generated.h"

UENUM(BlueprintType)
enum class EWeaponAttachmentTransformRules : uint8 {
    SnapToTargetNotIncludingScale,
    SnapToTargetIncludingScale,
    KeepRelativeTransform,
    KeepWorldTransform,
};

