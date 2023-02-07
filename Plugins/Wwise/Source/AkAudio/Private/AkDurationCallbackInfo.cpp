#include "AkDurationCallbackInfo.h"

UAkDurationCallbackInfo::UAkDurationCallbackInfo() {
    this->Duration = 0.00f;
    this->EstimatedDuration = 0.00f;
    this->AudioNodeID = 0;
    this->MediaID = 0;
    this->bStreaming = false;
}

