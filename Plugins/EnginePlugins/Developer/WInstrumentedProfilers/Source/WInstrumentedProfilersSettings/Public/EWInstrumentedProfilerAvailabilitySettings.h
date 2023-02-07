#pragma once
#include "CoreMinimal.h"
#include "EWInstrumentedProfilerAvailabilitySettings.generated.h"

UENUM()
enum class EWInstrumentedProfilerAvailabilitySettings : uint32 {
    NotSelected,
    Disabled,
    Minimal,
    Standard,
    Detailed,
    Debug,
};

