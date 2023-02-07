#pragma once
#include "CoreMinimal.h"
#include "UStreamlineDLSSGSupport.generated.h"

UENUM(BlueprintType)
enum class UStreamlineDLSSGSupport : uint8 {
    Supported,
    NotSupported,
    NotSupportedIncompatibleHardware,
    NotSupportedDriverOutOfDate,
    NotSupportedOperatingSystemOutOfDate,
    NotSupportedByPlatformAtBuildTime,
    NotSupportedIncompatibleAPICaptureToolActive,
};

