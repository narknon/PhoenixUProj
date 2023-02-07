#pragma once
#include "CoreMinimal.h"
#include "EAkChannelConfigType.generated.h"

UENUM()
enum class EAkChannelConfigType : int32 {
    Anonymous,
    Standard,
    Ambisonic,
};

