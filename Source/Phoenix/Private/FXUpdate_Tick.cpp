#include "FXUpdate_Tick.h"

class UMultiFX2_Base;

void UFXUpdate_Tick::Update(FMultiFX2Handle InHandle, const UMultiFX2_Base* InMultiBase) {
}

UFXUpdate_Tick::UFXUpdate_Tick() {
    this->UpdateRate = 0.02f;
}

