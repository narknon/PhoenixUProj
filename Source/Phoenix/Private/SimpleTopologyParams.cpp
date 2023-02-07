#include "SimpleTopologyParams.h"

FSimpleTopologyParams::FSimpleTopologyParams() {
    this->VoxelSize = 0.00f;
    this->SweepDistanceZ = 0.00f;
    this->bUseBoxSweeps = false;
    this->bSolidsOnly = false;
    this->bTraceComplex = false;
    this->bForceSynchronous = false;
}

