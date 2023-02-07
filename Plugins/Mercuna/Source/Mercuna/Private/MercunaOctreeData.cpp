#include "MercunaOctreeData.h"

FMercunaOctreeData::FMercunaOctreeData() {
    this->CellSize = 0.00f;
    this->MinPawnRadius = 0;
    this->MaxPawnRadius = 0;
    this->bAllowOctreeMerging = false;
    this->bRecordOctreeDeltas = false;
}

