#pragma once
#include "CoreMinimal.h"
#include "EAkAudioSessionCategory.generated.h"

UENUM()
enum class EAkAudioSessionCategory : int32 {
    Ambient,
    SoloAmbient,
    PlayAndRecord,
};

