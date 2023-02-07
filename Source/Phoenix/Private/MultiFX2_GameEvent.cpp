#include "MultiFX2_GameEvent.h"

UMultiFX2_GameEvent::UMultiFX2_GameEvent() {
    this->Intensity = EGameEvent_Intensity::White;
    this->Duration = 0.00f;
    this->Range = -1.00f;
    this->Falloff = 0.00f;
}

