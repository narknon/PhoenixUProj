#pragma once
#include "CoreMinimal.h"
#include "ESceneActionAdaptationAffect.generated.h"

UENUM(BlueprintType)
enum class ESceneActionAdaptationAffect : uint8 {
    Bloom,
    AutoExposure,
    Luminance,
};

