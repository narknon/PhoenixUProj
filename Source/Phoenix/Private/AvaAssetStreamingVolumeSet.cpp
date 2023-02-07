#include "AvaAssetStreamingVolumeSet.h"

class AActor;
class UObject;

void AAvaAssetStreamingVolumeSet::SetAssetOwner(AActor* NewOwner) {
}

TArray<FTransform> AAvaAssetStreamingVolumeSet::GetAssetTransforms() {
    return TArray<FTransform>();
}

TArray<TSoftObjectPtr<UObject>> AAvaAssetStreamingVolumeSet::GetAssetsToStream() {
    return TArray<TSoftObjectPtr<UObject>>();
}

AActor* AAvaAssetStreamingVolumeSet::GetAssetOwner() {
    return NULL;
}

AAvaAssetStreamingVolumeSet::AAvaAssetStreamingVolumeSet() {
    this->AssetOwner = NULL;
}

