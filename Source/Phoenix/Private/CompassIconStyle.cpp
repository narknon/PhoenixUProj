#include "CompassIconStyle.h"

FCompassIconStyle::FCompassIconStyle() {
    this->IconBaseScale = 0.00f;
    this->IconElevationScale = 0.00f;
    this->HasAlternateTexture = false;
    this->ShowOnMinimap = false;
    this->ShowOnHUD = false;
    this->LockToHUD = false;
    this->HudViewDistHogwarts = 0.00f;
    this->HudViewDistOverland = 0.00f;
    this->HudMinViewDist = 0.00f;
    this->BroomRevelio = false;
    this->ShowHudDistanceNums = false;
    this->ShouldClearOnComplete = false;
    this->ReplayableOnComplete = false;
    this->HasCompleteTexture = false;
    this->NeedsGlint = false;
    this->MaxDistance = 0.00f;
    this->MinDistance = 0.00f;
    this->Priority = 0.00f;
    this->ShowPulsingIcon = false;
}

