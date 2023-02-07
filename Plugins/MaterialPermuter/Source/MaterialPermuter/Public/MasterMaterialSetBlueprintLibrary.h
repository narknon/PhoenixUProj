#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MasterMaterialAssetSet.h"
#include "MasterMaterialSet.h"
#include "MaterialPermuterGroupProperty.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterPermutationProperty.h"
#include "MaterialSwapRules.h"
#include "MasterMaterialSetBlueprintLibrary.generated.h"

class AActor;
class UMaterial;
class UMaterialInterface;
class UMeshComponent;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMasterMaterialSetBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMasterMaterialSetBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void RemoveFromMasterMaterialSet(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MasterMaterialSetToAssets(const FMasterMaterialSet& MaterialSet, TArray<TSoftObjectPtr<UMaterial>>& MasterMaterialAssets);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MasterMaterialSetNum(const FMasterMaterialSet& MaterialMasterSet, int32& NumMaterials);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MasterMaterialSetIsEmpty(const FMasterMaterialSet& MaterialMasterSet, bool& bIsEmpty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MasterMaterialSetContains(const FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey MakePermutationPropertyKey(FMaterialPermuterPermutationProperty PermutationProperty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeMeshMasterMaterialSet(UMeshComponent* Mesh);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeMeshesMasterMaterialSet(TArray<UMeshComponent*> Meshes);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey MakeMaterialPermuterKey(FName KeyHash);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeMasterMaterialSet(TArray<UMaterialInterface*> Materials);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialAssetSet MakeMasterMaterialAssetSet(const FMasterMaterialSet& MaterialMasterSet);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeKey(FMaterialPermuterKey& Key, FName Group, FName SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialPermuterKey MakeGroupPropertyKey(FMaterialPermuterGroupProperty GroupProperty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeActorsRulesMasterMaterialSet(TArray<AActor*> Actors, FMaterialSwapRules Rules);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeActorsMasterMaterialSet(TArray<AActor*> Actors, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeActorRulesMasterMaterialSet(AActor* Actor, FMaterialSwapRules Rules);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialSet MakeActorMasterMaterialSet(AActor* Actor, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void KeyIsValid(FMaterialPermuterKey Key, bool& bIsValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void KeyHasSubType(FMaterialPermuterKey Key, bool& bHasSubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void KeyGetSubType(FMaterialPermuterKey Key, FName& SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void KeyGetGroup(FMaterialPermuterKey Key, FName& Group);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetPermutationPropertyName(FMaterialPermuterPermutationProperty PermutationProperty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetMaterialPermuterKeyName(FMaterialPermuterKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetGroupPropertyName(FMaterialPermuterGroupProperty GroupProperty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMasterMaterialAssetSet CreateMasterMaterialAssetSet(TArray<TSoftObjectPtr<UMaterial>> MaterialAssets);
    
    UFUNCTION(BlueprintCallable)
    static void CombineMasterMaterialSets(const FMasterMaterialSet& A, const FMasterMaterialSet& B, FMasterMaterialSet& Combined);
    
    UFUNCTION(BlueprintCallable)
    static void AppendMasterMaterialSet(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, const FMasterMaterialSet& Add);
    
    UFUNCTION(BlueprintCallable)
    static void AppendActorToMasterMaterialSetWithRules(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, AActor* Actor, FMaterialSwapRules Rules);
    
    UFUNCTION(BlueprintCallable)
    static void AppendActorToMasterMaterialSet(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, AActor* Actor, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable)
    static void AppendActorsToMasterMaterialSetWithRules(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, TArray<AActor*> Actors, FMaterialSwapRules Rules);
    
    UFUNCTION(BlueprintCallable)
    static void AppendActorsToMasterMaterialSet(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, TArray<AActor*> Actors, bool bAttachedChildren, bool bComponentChildren);
    
    UFUNCTION(BlueprintCallable)
    static void AddToMasterMaterialSet(UPARAM(Ref) FMasterMaterialSet& MaterialMasterSet, UMaterialInterface* Material);
    
};

