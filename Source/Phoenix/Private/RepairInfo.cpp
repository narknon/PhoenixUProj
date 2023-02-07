#include "RepairInfo.h"

URepairInfo::URepairInfo() {
    this->DestructibleGeometryCollection = NULL;
    this->BaseMesh = NULL;
    this->ChunkPhysicalMaterial = NULL;
    this->DeathNoiseSize = ENoiseSize::NoNoise;
    this->ChunkTrailVfx = NULL;
    this->ChunkFadeVfx = NULL;
    this->ChunkImpactVfx = NULL;
    this->RepairSfx = NULL;
    this->ReparoDataPtr = NULL;
    this->DestroyObjectFieldSystemClass = NULL;
    this->MaxClusterLevel = 0;
    this->bSimpleDestroy = false;
}

