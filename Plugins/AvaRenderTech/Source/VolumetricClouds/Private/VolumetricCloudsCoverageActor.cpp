#include "VolumetricCloudsCoverageActor.h"
#include "VolumetricCloudsCoverageComponent.h"

AVolumetricCloudsCoverageActor::AVolumetricCloudsCoverageActor() {
    this->CoverageComponent = CreateDefaultSubobject<UVolumetricCloudsCoverageComponent>(TEXT("VolumetricCloudsCoverageComponent0"));
}

