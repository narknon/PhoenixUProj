#include "DungeonWaterVolume.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

class UStaticMesh;

void ADungeonWaterVolume::SetupWater(FBoxSphereBounds i_Bounds, UStaticMesh* i_SurfaceMesh, const FVector& i_SurfaceLocation, UStaticMesh* i_DeepCollision, const FVector& i_DeepLocation, UStaticMesh* i_ShallowCollision, const FVector& i_ShallowLocation) {
}

void ADungeonWaterVolume::FinalizeSetup() {
}

ADungeonWaterVolume::ADungeonWaterVolume() {
    this->RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->SurfacePlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SurfacePlane"));
    this->bShallowWater = false;
    this->WaterMaterial = NULL;
}

