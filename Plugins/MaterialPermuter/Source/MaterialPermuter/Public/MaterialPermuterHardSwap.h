#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialPermuterHardSwapRules.h"
#include "MaterialPermuterHardSwapSimple.h"
#include "MaterialSwapSharedMIDCache.h"
#include "MaterialPermuterHardSwap.generated.h"

class AActor;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterHardSwap : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMaterialPermuterHardSwap();
    UFUNCTION(BlueprintCallable)
    static void SwapFromdHardSwapCacheWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped);
    
    UFUNCTION(BlueprintCallable)
    static void SwapFromdHardSwapCache(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped);
    
    UFUNCTION(BlueprintCallable)
    static void SwapActorsFromdHardSwapCacheWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped);
    
    UFUNCTION(BlueprintCallable)
    static void SwapActorsFromdHardSwapCache(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, const FMaterialSwapSharedMIDCache& HardSwapCache, int32& MaterialsSwapped);
    
    UFUNCTION(BlueprintCallable)
    static void SetMIDArrayVectorParameter(const TArray<UMaterialInstanceDynamic*> MaterialInstanceDynamics, FName Parameter, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetMIDArrayScalarParameter(const TArray<UMaterialInstanceDynamic*> MaterialInstanceDynamics, FName Parameter, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapCacheToMaterials(const FMaterialSwapSharedMIDCache& HardSwapCache, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActorWithRulesNoMIDs(AActor* Actor, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActorWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActorsWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActors(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActorNoMIDs(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void HardSwapActor(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, int32& MaterialsSwapped, TArray<UMaterialInstanceDynamic*>& MaterialInstanceDynamics, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void BuildHardSwapCacheWithRules(AActor* Actor, FMaterialPermuterHardSwapRules Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void BuildHardSwapCacheForActorsWithRules(TArray<AActor*> Actors, FMaterialPermuterHardSwapRules Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void BuildHardSwapCacheForActors(TArray<AActor*> Actors, FMaterialPermuterHardSwapSimple Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials);
    
    UFUNCTION(BlueprintCallable)
    static void BuildHardSwapCache(AActor* Actor, FMaterialPermuterHardSwapSimple Swap, FMaterialSwapSharedMIDCache& HardSwapCache, bool bForceLoadMaterials);
    
};

