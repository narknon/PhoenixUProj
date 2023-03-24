#include "HoudiniAssetActor.h"
#include "HoudiniAssetComponent.h"

AHoudiniAssetActor::AHoudiniAssetActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HoudiniAssetComponent = CreateDefaultSubobject<UHoudiniAssetComponent>(TEXT("HoudiniAssetComponent"));
}

