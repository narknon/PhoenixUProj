#include "MasterTickThrottlerSettings.h"

FMasterTickThrottlerSettings::FMasterTickThrottlerSettings() {
    this->FullTickRadiusMeters = 0.00f;
    this->FullTickInterval = 0.00f;
    this->NoTickRadiusMeters = 0.00f;
    this->NoTickInterval = 0.00f;
    this->KeepAliveInterval = 0.00f;
    this->ComparisonComponent = NULL;
}

