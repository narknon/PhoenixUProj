#include "OdcDebugDrawActor.h"
#include "Components/LineBatchComponent.h"
#include "OdcCanvasTextComponent.h"

AOdcDebugDrawActor::AOdcDebugDrawActor() {
    this->CanvasTextComponent = CreateDefaultSubobject<UOdcCanvasTextComponent>(TEXT("DefaultNavMeshDrawComponent"));
    this->LineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("DefaultLineBatchComponent"));
    this->DebugPanel = NULL;
}

