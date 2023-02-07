#include "MaterialPermuterLoadingBundle.h"

class AActor;
class UMaterialPermuterLoadingBundle;
class UObject;

void UMaterialPermuterLoadingBundle::ValidBundle(bool& bValid) const {
}

AActor* UMaterialPermuterLoadingBundle::GetWorldBundleOwner(UObject* WorldContextObject) {
    return NULL;
}

void UMaterialPermuterLoadingBundle::GetPercentageLoaded(float& Loaded) const {
}

void UMaterialPermuterLoadingBundle::FullyLoaded(bool& bIsFullyLoaded) const {
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateMaterialSetBundleForOwnerOnly(AActor* Owner, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateMaterialSetBundle(AActor* Owner, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeysMaterialSetBundle(AActor* Owner, TArray<FMaterialPermuterKey> Keys, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeysBundleForOwnerOnly(AActor* Owner, TArray<FMaterialPermuterKey> Keys, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeysBundle(AActor* Owner, TArray<FMaterialPermuterKey> Keys, EMaterialPermuterLoadingPriority NewPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeyMaterialSetBundle(AActor* Owner, FMaterialPermuterKey Key, const FMasterMaterialAssetSet& MaterialAssetSet, EMaterialPermuterLoadingPriority NewPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeyBundleForOwnerOnly(AActor* Owner, FMaterialPermuterKey Key, EMaterialPermuterLoadingPriority NewPriority, bool bAttachedChildren, bool bComponentChildren) {
    return NULL;
}

UMaterialPermuterLoadingBundle* UMaterialPermuterLoadingBundle::CreateKeyBundle(AActor* Owner, FMaterialPermuterKey Key, EMaterialPermuterLoadingPriority NewPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundle::UMaterialPermuterLoadingBundle() {
    this->Priority = EMaterialPermuterLoadingPriority::Normal;
    this->State = EMaterialPermuterLoadingBundleState::Init;
    this->TimeWarnings = 0;
    this->LastPercentageBroadcast = -1.00f;
}

