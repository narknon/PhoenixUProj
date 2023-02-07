#pragma once
#include "CoreMinimal.h"
#include "ESkinFXSocketOutputAlphaPack.generated.h"

UENUM(BlueprintType)
enum class ESkinFXSocketOutputAlphaPack : uint8 {
    SFXSAP_NONE,
    SFXSAP_SPEED,
    SFXSAP_SCALE,
    SFXSAP_MAX UMETA(Hidden),
};

