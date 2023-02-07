#pragma once
#include "CoreMinimal.h"
#include "EAudioVisualizerType.generated.h"

UENUM(BlueprintType)
enum class EAudioVisualizerType : uint8 {
    Footsteps,
    Spells,
    Dialogue,
};

