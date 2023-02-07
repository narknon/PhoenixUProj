#include "AvaAssetStreamingVolumeComponent.h"

class AActor;
class UObject;

void UAvaAssetStreamingVolumeComponent::SetAssetOwner(AActor* NewOwner) {
}

TArray<FTransform> UAvaAssetStreamingVolumeComponent::GetAssetTransforms() {
    return TArray<FTransform>();
}

TArray<TSoftObjectPtr<UObject>> UAvaAssetStreamingVolumeComponent::GetAssetsToStream() {
    return TArray<TSoftObjectPtr<UObject>>();
}

AActor* UAvaAssetStreamingVolumeComponent::GetAssetOwner() {
    return NULL;
}

UAvaAssetStreamingVolumeComponent::UAvaAssetStreamingVolumeComponent() {
    this->AssetOwner = NULL;
}

