#pragma once
#include "CoreMinimal.h"
#include "EAkMidiEventType.generated.h"

UENUM(BlueprintType)
enum class EAkMidiEventType : uint8 {
    AkMidiEventTypeInvalid,
    AkMidiEventTypeNoteOff = 0x80,
    AkMidiEventTypeNoteOn = 0x90,
    AkMidiEventTypeNoteAftertouch = 0xA0,
    AkMidiEventTypeController = 0xB0,
    AkMidiEventTypeProgramChange = 0xC0,
    AkMidiEventTypeChannelAftertouch = 0xD0,
    AkMidiEventTypePitchBend = 0xE0,
    AkMidiEventTypeSysex = 0xF0,
    AkMidiEventTypeEscape = 0xF7,
    AkMidiEventTypeMeta = 0xFF,
};

