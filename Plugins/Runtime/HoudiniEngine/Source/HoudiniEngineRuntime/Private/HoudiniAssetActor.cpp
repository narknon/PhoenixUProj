#include "HoudiniAssetActor.h"
#include "HoudiniAssetComponent.h"

AHoudiniAssetActor::AHoudiniAssetActor() {
    this->HoudiniAssetComponent = CreateDefaultSubobject<UHoudiniAssetComponent>(TEXT("HoudiniAssetComponent"));
}

