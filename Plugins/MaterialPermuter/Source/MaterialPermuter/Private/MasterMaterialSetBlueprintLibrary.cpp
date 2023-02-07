#include "MasterMaterialSetBlueprintLibrary.h"

class AActor;
class UMaterial;
class UMaterialInterface;
class UMeshComponent;

void UMasterMaterialSetBlueprintLibrary::RemoveFromMasterMaterialSet(FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material) {
}

void UMasterMaterialSetBlueprintLibrary::MasterMaterialSetToAssets(const FMasterMaterialSet& MaterialSet, TArray<TSoftObjectPtr<UMaterial>>& MasterMaterialAssets) {
}

void UMasterMaterialSetBlueprintLibrary::MasterMaterialSetNum(const FMasterMaterialSet& MaterialMasterSet, int32& NumMaterials) {
}

void UMasterMaterialSetBlueprintLibrary::MasterMaterialSetIsEmpty(const FMasterMaterialSet& MaterialMasterSet, bool& bIsEmpty) {
}

void UMasterMaterialSetBlueprintLibrary::MasterMaterialSetContains(const FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material) {
}

FMaterialPermuterKey UMasterMaterialSetBlueprintLibrary::MakePermutationPropertyKey(FMaterialPermuterPermutationProperty PermutationProperty) {
    return FMaterialPermuterKey{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeMeshMasterMaterialSet(UMeshComponent* Mesh) {
    return FMasterMaterialSet{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeMeshesMasterMaterialSet(TArray<UMeshComponent*> Meshes) {
    return FMasterMaterialSet{};
}

FMaterialPermuterKey UMasterMaterialSetBlueprintLibrary::MakeMaterialPermuterKey(FName KeyHash) {
    return FMaterialPermuterKey{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeMasterMaterialSet(TArray<UMaterialInterface*> Materials) {
    return FMasterMaterialSet{};
}

FMasterMaterialAssetSet UMasterMaterialSetBlueprintLibrary::MakeMasterMaterialAssetSet(const FMasterMaterialSet& MaterialMasterSet) {
    return FMasterMaterialAssetSet{};
}

void UMasterMaterialSetBlueprintLibrary::MakeKey(FMaterialPermuterKey& Key, FName Group, FName SubType) {
}

FMaterialPermuterKey UMasterMaterialSetBlueprintLibrary::MakeGroupPropertyKey(FMaterialPermuterGroupProperty GroupProperty) {
    return FMaterialPermuterKey{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeActorsRulesMasterMaterialSet(TArray<AActor*> Actors, FMaterialSwapRules Rules) {
    return FMasterMaterialSet{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeActorsMasterMaterialSet(TArray<AActor*> Actors, bool bAttachedChildren, bool bComponentChildren) {
    return FMasterMaterialSet{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeActorRulesMasterMaterialSet(AActor* Actor, FMaterialSwapRules Rules) {
    return FMasterMaterialSet{};
}

FMasterMaterialSet UMasterMaterialSetBlueprintLibrary::MakeActorMasterMaterialSet(AActor* Actor, bool bAttachedChildren, bool bComponentChildren) {
    return FMasterMaterialSet{};
}

void UMasterMaterialSetBlueprintLibrary::KeyIsValid(FMaterialPermuterKey Key, bool& bIsValid) {
}

void UMasterMaterialSetBlueprintLibrary::KeyHasSubType(FMaterialPermuterKey Key, bool& bHasSubType) {
}

void UMasterMaterialSetBlueprintLibrary::KeyGetSubType(FMaterialPermuterKey Key, FName& SubType) {
}

void UMasterMaterialSetBlueprintLibrary::KeyGetGroup(FMaterialPermuterKey Key, FName& Group) {
}

FName UMasterMaterialSetBlueprintLibrary::GetPermutationPropertyName(FMaterialPermuterPermutationProperty PermutationProperty) {
    return NAME_None;
}

FName UMasterMaterialSetBlueprintLibrary::GetMaterialPermuterKeyName(FMaterialPermuterKey Key) {
    return NAME_None;
}

FName UMasterMaterialSetBlueprintLibrary::GetGroupPropertyName(FMaterialPermuterGroupProperty GroupProperty) {
    return NAME_None;
}

FMasterMaterialAssetSet UMasterMaterialSetBlueprintLibrary::CreateMasterMaterialAssetSet(TArray<TSoftObjectPtr<UMaterial>> MaterialAssets) {
    return FMasterMaterialAssetSet{};
}

void UMasterMaterialSetBlueprintLibrary::CombineMasterMaterialSets(const FMasterMaterialSet& A, const FMasterMaterialSet& B, FMasterMaterialSet& Combined) {
}

void UMasterMaterialSetBlueprintLibrary::AppendMasterMaterialSet(FMasterMaterialSet& MaterialMasterSet, const FMasterMaterialSet& Add) {
}

void UMasterMaterialSetBlueprintLibrary::AppendActorToMasterMaterialSetWithRules(FMasterMaterialSet& MaterialMasterSet, AActor* Actor, FMaterialSwapRules Rules) {
}

void UMasterMaterialSetBlueprintLibrary::AppendActorToMasterMaterialSet(FMasterMaterialSet& MaterialMasterSet, AActor* Actor, bool bAttachedChildren, bool bComponentChildren) {
}

void UMasterMaterialSetBlueprintLibrary::AppendActorsToMasterMaterialSetWithRules(FMasterMaterialSet& MaterialMasterSet, TArray<AActor*> Actors, FMaterialSwapRules Rules) {
}

void UMasterMaterialSetBlueprintLibrary::AppendActorsToMasterMaterialSet(FMasterMaterialSet& MaterialMasterSet, TArray<AActor*> Actors, bool bAttachedChildren, bool bComponentChildren) {
}

void UMasterMaterialSetBlueprintLibrary::AddToMasterMaterialSet(FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material) {
}

UMasterMaterialSetBlueprintLibrary::UMasterMaterialSetBlueprintLibrary() {
}

