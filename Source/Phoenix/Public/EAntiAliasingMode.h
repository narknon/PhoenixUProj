#pragma once
#include "CoreMinimal.h"
#include "EAntiAliasingMode.generated.h"

UENUM(BlueprintType)
enum class EAntiAliasingMode : uint8 {
    TAA_Low,
    TAA_High,
    Nvidia_DLAA,
};

