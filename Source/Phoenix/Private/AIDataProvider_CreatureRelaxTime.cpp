#include "AIDataProvider_CreatureRelaxTime.h"

UAIDataProvider_CreatureRelaxTime::UAIDataProvider_CreatureRelaxTime() {
    this->Stance = ECreatureStance::Standing;
    this->RangeType = ECreatureDataProviderValueRangeType::Random;
}

