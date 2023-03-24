#include "WindSourceDebugActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "WindSourceDebugUpdateComponent.h"

AWindSourceDebugActor::AWindSourceDebugActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PointsXY = 8;
    this->PointsZ = 1;
    this->SpacingXY = 100.00f;
    this->SpacingZ = 100.00f;
    this->WindArrowMeshMaterialOverride = NULL;
    this->bExactIndoors = true;
    this->bPerSampleInsideTesting = false;
    this->bWindSpeedLengthScaling = true;
    this->UpdatePump = CreateDefaultSubobject<UWindSourceDebugUpdateComponent>(TEXT("WindSourceDebugUpdate"));
    this->WindArrows = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WindArrows"));
}

