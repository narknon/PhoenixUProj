#pragma once
#include "CoreMinimal.h"
#include "EAkAudioSessionCategoryOptions.generated.h"

UENUM(BlueprintType)
enum class EAkAudioSessionCategoryOptions : uint8 {
    MixWithOthers,
    DuckOthers,
    AllowBluetooth,
    DefaultToSpeaker,
};

