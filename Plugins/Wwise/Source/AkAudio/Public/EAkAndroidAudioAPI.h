#pragma once
#include "CoreMinimal.h"
#include "EAkAndroidAudioAPI.generated.h"

UENUM(BlueprintType)
enum class EAkAndroidAudioAPI : uint8 {
    AAudio,
    OpenSL_ES,
};

