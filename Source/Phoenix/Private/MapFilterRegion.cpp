#include "MapFilterRegion.h"

class UTexture2D;

void AMapFilterRegion::SetTexture(UTexture2D* inTexture) {
}

FString AMapFilterRegion::GetName() {
    return TEXT("");
}

AMapFilterRegion::AMapFilterRegion(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Material = NULL;
}

