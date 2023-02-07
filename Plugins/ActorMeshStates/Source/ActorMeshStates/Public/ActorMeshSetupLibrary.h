#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorMeshSetupName.h"
#include "ActorMeshSetupLibrary.generated.h"

class AActor;
class UMeshComponent;

UCLASS(Blueprintable)
class ACTORMESHSTATES_API UActorMeshSetupLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UActorMeshSetupLibrary();
    UFUNCTION(BlueprintCallable)
    static void ActorMeshSetupRemoveMeshAlwaysIgnore(UMeshComponent* MeshComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ActorMeshSetupRemoveAlwaysIgnore(AActor* Actor, bool bIncludeChildren);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorMeshSetupProcessRefresh(AActor* Actor, bool bIncludeChildren);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorMeshSetupProcessNamed(AActor* Actor, FActorMeshSetupName MeshSetup, bool bIncludeChildren);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorMeshSetupProcessAuto(AActor* Actor, bool bIncludeChildren);
    
    UFUNCTION(BlueprintCallable)
    static void ActorMeshSetupAlwaysIgnoreMesh(UMeshComponent* MeshComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ActorMeshSetupAlwaysIgnore(AActor* Actor, bool bIncludeChildren);
    
};

