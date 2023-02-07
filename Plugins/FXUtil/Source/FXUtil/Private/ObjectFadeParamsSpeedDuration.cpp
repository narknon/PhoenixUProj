#include "ObjectFadeParamsSpeedDuration.h"

FObjectFadeParamsSpeedDuration::FObjectFadeParamsSpeedDuration() {
    this->Direction = EObjectFadeDirection::FadeIn;
    this->Speed = EObjectFadeSpeed::VeryFast;
    this->Duration = 0.00f;
    this->bUseDuration = false;
}

