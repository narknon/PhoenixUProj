#include "WorldFoliageData.h"

FWorldFoliageData::FWorldFoliageData() {
    this->LevelBoundsRadius = 0.00f;
    this->NumInstances = 0;
    this->NumAddedInstances = 0;
    this->bNeedsUpdate = false;
    this->CurrentState = ETileState::None;
}

