#include "LiveWeatherSequenceInfo.h"

ULiveWeatherSequenceInfo::ULiveWeatherSequenceInfo() {
    this->Sequence = NULL;
    this->Player = NULL;
    this->GamePlaybackScale = 1.00f;
    this->DynamicPlaybackScale = 1.00f;
    this->bKillASAP = false;
    this->bForceInstantChange = false;
    this->bCalledReadyToPlay = false;
    this->bPaused = false;
    this->bDone = false;
}

