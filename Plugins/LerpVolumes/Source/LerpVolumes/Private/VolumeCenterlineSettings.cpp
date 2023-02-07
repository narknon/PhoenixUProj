#include "VolumeCenterlineSettings.h"

FVolumeCenterlineSettings::FVolumeCenterlineSettings() {
    this->Mode = EVolumeCenterlineMode::None;
    this->CeilingFlatness = 0.00f;
    this->FloorFlatness = 0.00f;
}

