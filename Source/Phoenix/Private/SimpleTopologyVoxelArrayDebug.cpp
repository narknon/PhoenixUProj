#include "SimpleTopologyVoxelArrayDebug.h"

FSimpleTopologyVoxelArrayDebug::FSimpleTopologyVoxelArrayDebug() {
    this->bShowEmptySpace = false;
    this->bShowSurfaceVoxels = false;
    this->bShowSurfaceNormals = false;
    this->bShowPointCenterOffset = false;
    this->bShowSurfacePlanes = false;
    this->bShowInterior = false;
    this->bShowPendingCompute = false;
    this->PlaneOffset = 0.00f;
}

