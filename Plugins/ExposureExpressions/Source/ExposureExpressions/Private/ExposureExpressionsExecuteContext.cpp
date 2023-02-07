#include "ExposureExpressionsExecuteContext.h"

FExposureExpressionsExecuteContext::FExposureExpressionsExecuteContext() {
    this->World = NULL;
    this->Timestamp = 0;
    this->NightDay = 0.00f;
    this->Overcast = 0.00f;
    this->OutdoorsIndoors = 0.00f;
    this->FilteredOutdoorsIndoors = 0.00f;
}

