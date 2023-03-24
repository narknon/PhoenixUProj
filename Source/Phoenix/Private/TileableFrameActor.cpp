#include "TileableFrameActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneComponent.h"

void ATileableFrameActor::MakeFrame() {
}

ATileableFrameActor::ATileableFrameActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->InstRectTileMid = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstRectTileMid"));
    this->InstRectTileCorner = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstRectTileCorner"));
    this->RectangularFrameTile = NULL;
    this->RectangularFrameCorner = NULL;
    this->HorizontalTileCount = 0;
    this->VerticalTileCount = 0;
}

