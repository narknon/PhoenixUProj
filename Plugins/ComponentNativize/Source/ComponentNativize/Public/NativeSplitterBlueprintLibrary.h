#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeSplitterBlueprintLibrary.generated.h"

class UActorComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class COMPONENTNATIVIZE_API UNativeSplitterBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UNativeSplitterBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static bool RequiresOverrideVertexColorsFixup(UStaticMeshComponent* StaticMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveInstanceVertexColorsFromLOD(UStaticMeshComponent* StaticMeshComponent, int32 LODToRemoveColorsFrom);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveInstanceVertexColors(UStaticMeshComponent* StaticMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool FixupOverrideColorsIfNecessary(UStaticMeshComponent* StaticMeshComponent, bool bRebuildingStaticMesh);
    
    UFUNCTION(BlueprintCallable)
    static bool CopyProperties(UActorComponent* SourceComponent, UActorComponent* TargetComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool CopyInstanceVertexColorsIfCompatible(UStaticMeshComponent* SourceComponent, UStaticMeshComponent* TargetComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool CachePaintedDataIfNecessary(UStaticMeshComponent* StaticMeshComponent);
    
};

