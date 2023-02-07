#include "SpawnByPrimitiveOptionsDepthPriorityGroup.h"

USpawnByPrimitiveOptionsDepthPriorityGroup::USpawnByPrimitiveOptionsDepthPriorityGroup() {
    this->DepthPriorityGroup = SDPG_World;
    this->ViewOwnerDepthPriorityGroup = SDPG_World;
    this->bUseViewOwnerDepthPriorityGroup = false;
}

