#pragma once
#include "CoreMinimal.h"
#include "ECameraStackLookAtStrength.generated.h"

UENUM(BlueprintType)
enum class ECameraStackLookAtStrength : uint8 {
    None,
    SoftPitchHint,
    SoftHint,
    Strong,
    StrongOverTheShoulder,
    PlayerInitiated,
    NUM,
};

