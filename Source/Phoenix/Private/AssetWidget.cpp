#include "AssetWidget.h"

class UBlueprint;
class UObject;

UObject* UAssetWidget::SpawnObject(UObject* ObjectToSpawn) {
    return NULL;
}

void UAssetWidget::ShowAssetsInContentBrowser(TArray<UObject*>& InAssets) {
}

void UAssetWidget::ShowAssetInContentBrowser(UObject* Asset) {
}

void UAssetWidget::SetAsset(UObject* InAsset) {
}

UObject* UAssetWidget::GetSelectedAssetInContentBrowser(UClass* ObjectClass) {
    return NULL;
}

UClass* UAssetWidget::GetGeneratedClassFromBlueprint(UBlueprint* Blueprint) {
    return NULL;
}

UObject* UAssetWidget::GetAsset() {
    return NULL;
}

UBlueprint* UAssetWidget::CastToBlueprint(UObject* Object) {
    return NULL;
}

UAssetWidget::UAssetWidget() {
    this->Delegate = NULL;
}

