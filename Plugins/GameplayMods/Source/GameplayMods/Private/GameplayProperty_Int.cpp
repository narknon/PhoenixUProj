#include "GameplayProperty_Int.h"

FGameplayProperty_Int::FGameplayProperty_Int() {
    this->Current = 0;
    this->Base = 0;
    this->Min = 0;
    this->Max = 0;
    this->RoundingType = EPostCalculationRoundingType::RoundToNearest;
}

