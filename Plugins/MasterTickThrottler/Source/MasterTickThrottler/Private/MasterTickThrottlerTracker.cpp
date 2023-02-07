#include "MasterTickThrottlerTracker.h"

FMasterTickThrottlerTracker::FMasterTickThrottlerTracker() {
    this->bDisableThrottling = false;
    this->bHasKeepAliveInterface = false;
}

