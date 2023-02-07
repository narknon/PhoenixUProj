#include "GlobalLightGroupsGroupNameMap.h"

UGlobalLightGroupsGroupNameMap::UGlobalLightGroupsGroupNameMap() {
    this->GroupSchedules = NULL;
    this->LightComponentSchedules = NULL;
    this->ReferenceCount = 1;
    this->bForceGroup0OffGroup1On = false;
}

