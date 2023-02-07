#pragma once
#include "CoreMinimal.h"
#include "EAcknowledgementSpeakerType.generated.h"

UENUM(BlueprintType)
enum class EAcknowledgementSpeakerType : uint8 {
    ANY,
    COMPANION,
    DEEK,
    ENEMY,
    NONENEMY,
    NONE,
    PLAYER,
    VENDOR,
    COUNT,
};

