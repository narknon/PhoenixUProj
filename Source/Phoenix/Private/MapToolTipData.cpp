#include "MapToolTipData.h"

FMapToolTipData::FMapToolTipData() {
    this->BeaconInfo = NULL;
    this->CursorWidget = NULL;
    this->LevelRequirement = 0;
    this->Type = EMapToolTipTypes::MAP_TOOL_TIP_TYPE_UNSET;
    this->Distance = 0;
    this->ShouldShowDistance = false;
    this->ZoomType = EMapZoomTypes::MAP_TOOL_TIP_TYPE_INVALID;
    this->ShouldShowAvailableMissions = false;
    this->EnemyLevelMin = 0;
    this->EnemyLevelMax = 0;
}

