#include "WaterTileMeshComponent.h"

void UWaterTileMeshComponent::RebuildAccelerationStructure() {
}

UWaterTileMeshComponent::UWaterTileMeshComponent() {
    this->LakeSize = 0.00f;
    this->TextureDirAndDistToCoast = NULL;
    this->TextureFlowAndWaterDepth = NULL;
    this->HierarchicalInstancedTilesComponents.AddDefaulted(8);
}

