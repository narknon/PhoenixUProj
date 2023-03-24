#include "VolumetricCloudsCoverageActor.h"
#include "VolumetricCloudsCoverageComponent.h"

AVolumetricCloudsCoverageActor::AVolumetricCloudsCoverageActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CoverageComponent = CreateDefaultSubobject<UVolumetricCloudsCoverageComponent>(TEXT("VolumetricCloudsCoverageComponent0"));
}

