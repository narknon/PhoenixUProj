#include "MapIconAnimationsDataTable.h"

FMapIconAnimationsDataTable::FMapIconAnimationsDataTable() {
    this->AnimationTime = 0.00f;
    this->LoopType = MAP_ICON_ANIMATION_LOOP_TYPE_ONE_SHOT;
    this->Binding = MAP_ICON_ANIMATION_BINDING_TRANSLATION;
    this->SetType = MAP_ICON_ANIMATION_SET_TYPE_APPEND;
    this->LoopDelay = 0.00f;
    this->LerpToColor = false;
    this->OverlandScale = 0.00f;
    this->HogsmeadeScale = 0.00f;
    this->HogwartsScale = 0.00f;
    this->ScalingMultiplier = 0.00f;
}

