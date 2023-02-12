#include "AkMidiEventBase.h"

FAkMidiEventBase::FAkMidiEventBase() {
    this->Type = EAkMidiEventType::AkMidiEventTypeInvalid;
    this->Chan = 0;
}

