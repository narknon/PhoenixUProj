#include "AudioDialogueFlags.h"

FAudioDialogueFlags::FAudioDialogueFlags() {
    this->StartPausedUMETA = false;
    this->NoQueuingLimits = false;
    this->SuppressSubtitles = false;
    this->NonSpatialized = false;
    this->UseCinematicPolyphony = false;
    this->LipsyncFlags = ELipsyncFlags::NoLipsync;
}

