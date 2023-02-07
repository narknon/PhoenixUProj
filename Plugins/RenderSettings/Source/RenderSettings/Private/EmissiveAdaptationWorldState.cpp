#include "EmissiveAdaptationWorldState.h"

FEmissiveAdaptationWorldState::FEmissiveAdaptationWorldState() {
    this->World = NULL;
    this->NightDay = 0.00f;
    this->Overcast = 0.00f;
    this->OutdoorsIndoors = 0.00f;
    this->FilteredOutdoorsIndoors = 0.00f;
    this->bDayNightSystemValid = false;
}

