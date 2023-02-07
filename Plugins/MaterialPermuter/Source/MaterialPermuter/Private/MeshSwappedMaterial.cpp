#include "MeshSwappedMaterial.h"

FMeshSwappedMaterial::FMeshSwappedMaterial() {
    this->OriginalMaterial = NULL;
    this->SwapMID = NULL;
    this->Index = 0;
    this->flags = 0;
}

