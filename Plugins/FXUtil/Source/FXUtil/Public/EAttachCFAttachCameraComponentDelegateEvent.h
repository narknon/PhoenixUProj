#pragma once
#include "CoreMinimal.h"
#include "EAttachCFAttachCameraComponentDelegateEvent.generated.h"

UENUM(BlueprintType)
enum class EAttachCFAttachCameraComponentDelegateEvent : uint8 {
    PositionChanged,
    RotationChanged,
    PositionAndRotationChanged,
};

