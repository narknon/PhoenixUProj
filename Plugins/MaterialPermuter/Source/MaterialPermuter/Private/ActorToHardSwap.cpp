#include "ActorToHardSwap.h"

FActorToHardSwap::FActorToHardSwap() {
    this->ProcessMesh = 0;
    this->SwapMesh = 0;
    this->MaterialsSwapped = 0;
    this->bMeshesInitialized = false;
    this->bHaveBroadcastSwapped = false;
    this->bChildrenAreReady = false;
}

