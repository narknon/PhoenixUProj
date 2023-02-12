#pragma once
#include "CoreMinimal.h"
#include "EAkCallbackType.generated.h"

UENUM(BlueprintType)
enum class EAkCallbackType : uint8 {
    EndOfEvent,
    Marker = 0x2,
    Duration,
    Starvation = 0x5,
    MusicPlayStarted = 0x7,
    MusicSyncBeat,
    MusicSyncBar,
    MusicSyncEntry,
    MusicSyncExit,
    MusicSyncGrid,
    MusicSyncUserCue,
    MusicSyncPoint,
    MIDIEvent = 0x10,
};

