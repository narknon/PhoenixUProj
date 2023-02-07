#include "AnimTrackPlaybackOptions.h"

FAnimTrackPlaybackOptions::FAnimTrackPlaybackOptions() {
    this->PlayRateType = EAnimTrackPlaybackSpeed::NaturalSpeed;
    this->ForcedDuration = 0.00f;
    this->ForcedPlayRate = 0.00f;
}

