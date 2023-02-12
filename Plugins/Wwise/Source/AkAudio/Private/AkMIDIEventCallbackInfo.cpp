#include "AkMIDIEventCallbackInfo.h"

EAkMidiEventType UAkMIDIEventCallbackInfo::GetType() {
    return EAkMidiEventType::AkMidiEventTypeInvalid;
}

bool UAkMIDIEventCallbackInfo::GetProgramChange(FAkMidiProgramChange& AsProgramChange) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetPitchBend(FAkMidiPitchBend& AsPitchBend) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetNoteOn(FAkMidiNoteOnOff& AsNoteOn) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetNoteOff(FAkMidiNoteOnOff& AsNoteOff) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetNoteAftertouch(FAkMidiNoteAftertouch& AsNoteAftertouch) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetGeneric(FAkMidiGeneric& AsGeneric) {
    return false;
}

bool UAkMIDIEventCallbackInfo::GetChannelAftertouch(FAkMidiChannelAftertouch& AsChannelAftertouch) {
    return false;
}

uint8 UAkMIDIEventCallbackInfo::GetChannel() {
    return 0;
}

bool UAkMIDIEventCallbackInfo::GetCc(FAkMidiCc& AsCc) {
    return false;
}

UAkMIDIEventCallbackInfo::UAkMIDIEventCallbackInfo() {
}

