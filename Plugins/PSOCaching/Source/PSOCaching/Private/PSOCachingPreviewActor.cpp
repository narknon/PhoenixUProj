#include "PSOCachingPreviewActor.h"

class UObject;
class UPrimitiveComponent;

void APSOCachingPreviewActor::SetupManagedPrimitiveComponent(UPrimitiveComponent* InComponent) {
}

void APSOCachingPreviewActor::ResetStaticMeshPreview(UPrimitiveComponent* Primitive) {
}

void APSOCachingPreviewActor::ResetNiagaraSystemPreview(UPrimitiveComponent* Primitive) {
}

void APSOCachingPreviewActor::RegisterPreviewAssetTypeData(UClass* AssetType, const FPreviewAssetTypeData& AssetTypeData) {
}

void APSOCachingPreviewActor::RegisterAssetTypePreviewComponent(UClass* AssetType, UPrimitiveComponent* InComponent) {
}

void APSOCachingPreviewActor::ActivateStaticMeshPreview(UPrimitiveComponent* Primitive, UObject* Asset) {
}

void APSOCachingPreviewActor::ActivateNiagaraSystemPreview(UPrimitiveComponent* Primitive, UObject* Asset) {
}

APSOCachingPreviewActor::APSOCachingPreviewActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreviewMode = EPSOCachePreviewMode::FrameCount;
    this->PreviewFramesCount = 0;
    this->PreviewTime = 0.00f;
}

