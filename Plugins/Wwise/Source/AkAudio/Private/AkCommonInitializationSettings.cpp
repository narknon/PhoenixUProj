#include "AkCommonInitializationSettings.h"

FAkCommonInitializationSettings::FAkCommonInitializationSettings() {
    this->MaximumNumberOfMemoryPools = 0;
    this->MaximumNumberOfPositioningPaths = 0;
    this->CommandQueueSize = 0;
    this->SamplesPerFrame = 0;
    this->StreamingLookAheadRatio = 0.00f;
    this->NumberOfRefillsInVoice = 0;
}

