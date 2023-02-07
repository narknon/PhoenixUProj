#include "HardSwapBatchComponentSettings.h"

FHardSwapBatchComponentSettings::FHardSwapBatchComponentSettings() {
    this->MIDCreatesAllowedPerFrame = 0;
    this->MaterialsToSwapPerFrame = 0;
    this->bDetachAndDestoryWhenDone = false;
}

