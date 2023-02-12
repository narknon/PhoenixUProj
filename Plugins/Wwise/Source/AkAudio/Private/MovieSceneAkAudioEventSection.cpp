#include "MovieSceneAkAudioEventSection.h"

UMovieSceneAkAudioEventSection::UMovieSceneAkAudioEventSection() {
    this->Event = NULL;
    this->RetriggerEvent = false;
    this->ScrubTailLengthMs = 100;
    this->StopAtSectionEnd = true;
    this->MaxSourceDuration = -1.00f;
}

