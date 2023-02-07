#include "SpawnByPrimitiveOptionsCustomDepth.h"

USpawnByPrimitiveOptionsCustomDepth::USpawnByPrimitiveOptionsCustomDepth() {
    this->bRenderCustomDepth = true;
    this->CustomDepthStencilWriteMask = ERendererStencilMask::ERSM_Default;
    this->CustomDepthStencilValue = 0;
}

