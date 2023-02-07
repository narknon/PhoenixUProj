#pragma once
#include "CoreMinimal.h"
#include "EGenderVoice.generated.h"

UENUM(BlueprintType)
enum class EGenderVoice : uint8 {
    VOICE_MALE,
    VOICE_FEMALE,
    VOICE_MAX UMETA(Hidden),
};

