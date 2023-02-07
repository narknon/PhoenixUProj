#include "VolumetricCloudsPreviewActor.h"
#include "VolumetricCloudsPreviewComponent.h"

AVolumetricCloudsPreviewActor::AVolumetricCloudsPreviewActor() {
    this->PreviewComponent = CreateDefaultSubobject<UVolumetricCloudsPreviewComponent>(TEXT("VolumetricCloudsPreviewComponent0"));
}

