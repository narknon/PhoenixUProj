#include "SharedMapData.h"

USharedMapData::USharedMapData() {
    this->PathDirectionShortDotsTimerMax = 1.50f;
    this->PathDirectionMediumDotsThreshold = 10;
    this->PathDirectionMediumDotsTimerMax = 1.50f;
    this->PathDirectionLongDotsThreshold = 50;
    this->PathDirectionLongDotsTimerMax = 1.00f;
    this->PathDirectionTimerMax = 0.10f;
    this->DirectionIndicatorLength = 3;
    this->OverlandPathPointSpacingModifier = 1.00f;
    this->HogwartsPathPointSpacingModifier = 1.00f;
    this->HogwartsZoomedPathPointSpacingModifier = 1.00f;
    this->HogsmeadePathPointSpacingModifier = 1.00f;
    this->IconScale = 0.20f;
    this->MinimumTimeBeforeRestart = 2.00f;
}

