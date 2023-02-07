#include "GlobalLightGroupsRegionGroupRegistry.h"

UGlobalLightGroupsRegionGroupRegistry::UGlobalLightGroupsRegionGroupRegistry() {
    this->RegionGroups.AddDefaulted(1);
    this->RegionFreeLightComponentSchedules = NULL;
}

