#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialPermuter.generated.h"

class AActor;
class UMaterialInterface;
class UMeshComponent;
class UObject;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuter : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMaterialPermuter();
    UFUNCTION(BlueprintCallable)
    static void MaterialPermuterSetBaseMaterial(UMeshComponent* Mesh, int32 Index, UMaterialInterface* Material, bool& Success);
    
    UFUNCTION(BlueprintCallable)
    static void MaterialPermuterPrepareSetBaseMaterials(UMeshComponent* Mesh, bool& Success);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterIsMeshSwapped(UMeshComponent* Mesh, bool& bIsSwapped);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialPermuterGetMeshSwapOwner(UMeshComponent* Mesh, UObject*& SwapOwner);
    
    UFUNCTION(BlueprintCallable)
    static void MaterialPermuterClearMeshSwap(UMeshComponent* Mesh, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void MaterialPermuterClearAllSwaps(AActor* Actor, bool& bSuccess);
    
};

