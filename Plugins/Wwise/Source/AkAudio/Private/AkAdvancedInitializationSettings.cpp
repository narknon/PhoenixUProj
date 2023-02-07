#include "AkAdvancedInitializationSettings.h"

FAkAdvancedInitializationSettings::FAkAdvancedInitializationSettings() {
    this->IO_MemorySize = 0;
    this->IO_Granularity = 0;
    this->TargetAutoStreamBufferLength = 0.00f;
    this->UseStreamCache = false;
    this->MaximumPinnedBytesInCache = 0;
    this->EnableGameSyncPreparation = false;
    this->ContinuousPlaybackLookAhead = 0;
    this->MonitorQueuePoolSize = 0;
    this->MaximumHardwareTimeoutMs = 0;
    this->DebugOutOfRangeCheckEnabled = false;
    this->DebugOutOfRangeLimit = 0.00f;
}

