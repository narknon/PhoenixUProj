#include "MaterialPermuterHardSwap.h"

class AActor;
class UMaterialInstanceDynamic;

void UMaterialPermuterHardSwap::SwapFromdHardSwapCacheWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped) {
}

void UMaterialPermuterHardSwap::SwapFromdHardSwapCache(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped) {
}

void UMaterialPermuterHardSwap::SwapActorsFromdHardSwapCacheWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped) {
}

void UMaterialPermuterHardSwap::SwapActorsFromdHardSwapCache(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped) {
}

void UMaterialPermuterHardSwap::SetMIDArrayVectorParameter(const TArray<UMaterialInstanceDynamic*> MaterialInstanceDynamics, FName Parameter, FLinearColor Value) {
}

void UMaterialPermuterHardSwap::SetMIDArrayScalarParameter(const TArray<UMaterialInstanceDynamic*> MaterialInstanceDynamics, FName Parameter, float Value) {
}

void UMaterialPermuterHardSwap::HardSwapCacheToMaterials(const FMaterialSwapSharedMIDCache& HardSwapCache, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics) {
}

void UMaterialPermuterHardSwap::HardSwapActorWithRulesNoMIDs(AActor* Actor, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::HardSwapActorWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::HardSwapActorsWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::HardSwapActors(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::HardSwapActorNoMIDs(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::HardSwapActor(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::BuildHardSwapCacheWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::BuildHardSwapCacheForActorsWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::BuildHardSwapCacheForActors(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials) {
}

void UMaterialPermuterHardSwap::BuildHardSwapCache(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials) {
}

UMaterialPermuterHardSwap::UMaterialPermuterHardSwap() {
}

