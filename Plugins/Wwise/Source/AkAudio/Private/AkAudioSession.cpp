#include "AkAudioSession.h"

FAkAudioSession::FAkAudioSession() {
    this->AudioSessionCategory = EAkAudioSessionCategory::Ambient;
    this->AudioSessionCategoryOptions = 0;
    this->AudioSessionMode = EAkAudioSessionMode::Default;
}

