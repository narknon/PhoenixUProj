#include "AkMidiCc.h"

FAkMidiCc::FAkMidiCc() {
    this->Cc = EAkMidiCcValues::AkMidiCcBankSelectCoarse;
    this->Value = 0;
}

