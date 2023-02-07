#include "VCSlot.h"

FVCSlot::FVCSlot() {
    this->Type = EVCType::ITEM;
    this->Quantity = 0;
    this->QuantityHigh = 0;
    this->ItemIsUnique = false;
    this->ItemRandomWeight = 0;
    this->ItemWeightAdjust = 0;
    this->bShowInCurriculumRewards = false;
}

