#include "HUDCompassIcon.h"


















UHUDCompassIcon::UHUDCompassIcon() : UUserWidget(FObjectInitializer::Get()) {
    this->IsAnimating = false;
    this->InElevationRange = false;
    this->ShouldShowElevationHint = false;
    this->IsInPathedState = false;
    this->IsInLockedState = false;
}

