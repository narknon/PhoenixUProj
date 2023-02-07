#include "SharedMinimapData.h"

USharedMinimapData::USharedMinimapData() {
    this->PathDirectionTimerMax = 0.10f;
    this->DirectionIndicatorLength = 3;
    this->PathPointSpacingModifier = 1.00f;
    this->PathPointSpacingModifierHogsmeade = 0.01f;
    this->IconScale = 0.45f;
    this->AllowedOffMapDistanceModifier = 1.00f;
    this->MinimumTimeBeforeRestart = 2.00f;
    this->PathAlphaDecayFactor = 1.75f;
    this->MinimumPathAlpha = 0.15f;
    this->MaxHeightDelta = 1673.48f;
    this->MinimumPathPointScale = 0.50f;
    this->DefaultOverlapDistance = 40000.00f;
}

