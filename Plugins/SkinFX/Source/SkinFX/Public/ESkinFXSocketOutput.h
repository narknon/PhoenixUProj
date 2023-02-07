#pragma once
#include "CoreMinimal.h"
#include "ESkinFXSocketOutput.generated.h"

UENUM(BlueprintType)
enum class ESkinFXSocketOutput : uint8 {
    SFXS_POSITION,
    SFXS_VELOCITY,
    SFXS_VELOCITYDIR,
    SFXS_DIR,
    SFXS_UP,
    SFXS_RIGHT,
    SFXS_SCALE3D,
    SFXS_SCALARSPEED,
    SFXS_SCALARSCALEU,
    SFXS_MAX UMETA(Hidden),
};

