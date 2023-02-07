#include "FootPlantAnimNotify.h"

UFootPlantAnimNotify::UFootPlantAnimNotify() {
    this->NotifyName = TEXT("FootPlant");
    this->FootPlant = EFootPlantEnum::FOOTPLANT_NONE;
    this->bRegenerateOnCreatePhaseCurve = false;
    this->bIgnoreFootPlant = false;
    this->NotifyTime = 0.00f;
    this->TimeID = -1.00f;
    this->AudioMaxDistanceToListener = 5000.00f;
}

