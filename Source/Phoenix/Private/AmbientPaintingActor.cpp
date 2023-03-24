#include "AmbientPaintingActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicalResponseComponent.h"

AAmbientPaintingActor::AAmbientPaintingActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->FrameT = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrameT"));
    this->PaintingMaterial = NULL;
    this->AmbientPaintingsLibraryDT = NULL;
    this->PhysicalResponse = CreateDefaultSubobject<UPhysicalResponseComponent>(TEXT("PhysicalResponse"));
    this->BinkMediaPlayer = NULL;
    this->MaterialInstance = NULL;
}

