#include "AIGameEvent.h"

FAIGameEvent::FAIGameEvent() {
    this->Intensity = EGameEvent_Intensity::None;
    this->Duration = 0.00f;
    this->Range = 0.00f;
    this->Falloff = 0.00f;
    this->bTrackBackToInstigator = false;
    this->TraceBackStepSize = 0.00f;
    this->TraceBackRadius = 0.00f;
}

