#pragma once
#include "CoreMinimal.h"
#include "EAkAudioSessionMode.generated.h"

UENUM()
enum class EAkAudioSessionMode : int32 {
    Default,
    VoiceChat,
    GameChat,
    VideoRecording,
    Measurement,
    MoviePlayback,
    VideoChat,
};

