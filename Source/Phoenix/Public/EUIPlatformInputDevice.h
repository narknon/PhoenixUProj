#pragma once
#include "CoreMinimal.h"
#include "EUIPlatformInputDevice.generated.h"

UENUM(BlueprintType)
enum class EUIPlatformInputDevice : uint8 {
    UIPID_PS4,
    UIPID_XBOne,
    UIPID_PS5,
    UIPID_XSX,
    UIPID_Switch,
    UIPID_PC,
    UIPID_MAX UMETA(Hidden),
};

