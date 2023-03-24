#include "WaterVolume.h"
#include "Components/SceneComponent.h"
#include "LakeAudioComponent.h"

class UStaticMesh;

void AWaterVolume::SetupWater(FBoxSphereBounds i_Bounds, UStaticMesh* i_DeepCollision, const FVector& i_DeepLocation, UStaticMesh* i_ShallowCollision, const FVector& i_ShallowLocation) {
}

void AWaterVolume::RecalculateDepth() {
}

AWaterVolume::AWaterVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->WaterTileMeshComponent = NULL;
    this->LakeAudioComponent = CreateDefaultSubobject<ULakeAudioComponent>(TEXT("LakeAudio"));
}

