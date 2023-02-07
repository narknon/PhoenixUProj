#pragma once
#include "CoreMinimal.h"
#include "EWBPNPlatformLinkType.generated.h"

UENUM(BlueprintType)
enum EWBPNPlatformLinkType {
    WBPN_PLATFORM_INVALID,
    WBPN_PLATFORM_DISCORD,
    WBPN_PLATFORM_EPIC,
    WBPN_PLATFORM_MAX UMETA(Hidden),
};

