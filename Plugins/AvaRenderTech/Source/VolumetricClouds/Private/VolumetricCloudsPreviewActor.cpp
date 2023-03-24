#include "VolumetricCloudsPreviewActor.h"
#include "VolumetricCloudsPreviewComponent.h"

AVolumetricCloudsPreviewActor::AVolumetricCloudsPreviewActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreviewComponent = CreateDefaultSubobject<UVolumetricCloudsPreviewComponent>(TEXT("VolumetricCloudsPreviewComponent0"));
}

