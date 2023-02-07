#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapSphereSelectionType.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapSphereSelectionType : uint8 {
    UseComponentLocation,
    UseCameraLocation,
    UseManualLocation,
};

