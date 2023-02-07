#include "FXUpdate_Timed.h"

class UMultiFX2_Base;

void UFXUpdate_Timed::DeactivateFX(FMultiFX2Handle InHandle, const UMultiFX2_Base* FXBase) {
}

UFXUpdate_Timed::UFXUpdate_Timed() {
    this->Duration = 1.00f;
    this->bForceKill = true;
    this->World = NULL;
}

