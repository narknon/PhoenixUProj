#include "AblAvaAnimationPlaybackOptions.h"

FAblAvaAnimationPlaybackOptions::FAblAvaAnimationPlaybackOptions() {
    this->PlayRateType = EAnimTrackPlaybackSpeed::NaturalSpeed;
    this->ForcedDuration = NULL;
    this->ForcedPlayRate = NULL;
}

