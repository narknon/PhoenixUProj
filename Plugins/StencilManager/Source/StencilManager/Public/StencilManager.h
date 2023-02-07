#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StencilValueRenderCustomDepth.h"
#include "StencilManager.generated.h"

class AActor;
class AStencilManagerSingleton;
class UObject;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class STENCILMANAGER_API UStencilManager : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStencilManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnlockForStencil(UObject* WorldContextObject, UObject* LockOwner, UPrimitiveComponent* Component, bool& bSuccess, bool bRestore);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnlockAllForStencil(UObject* WorldContextObject, UObject* LockOwner, bool& bSuccess, bool bRestore);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool StencilGroupEnabled(UObject* WorldContextObject, FName Group);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool StencilEnabled(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void SetStencilValueRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, FStencilValueRenderCustomDepth StencilValueRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable)
    static void SetStencilValueAndRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, int32 StencilValue, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable)
    static void SetStencilValue(UPrimitiveComponent* PrimitiveComponent, int32 StencilValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetStencilEffect(AActor* InTarget, FName StencilEffect, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    static void SetStencil(AActor* InTarget, uint8 StencilValue, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    static void SetRenderCustomDepth(UPrimitiveComponent* PrimitiveComponent, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorStencilValueRenderCustomDepth(AActor* Actor, FStencilValueRenderCustomDepth StencilValueRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorStencilValueAndRenderCustomDepth(AActor* Actor, int32 StencilValue, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorStencilValue(AActor* Actor, int32 StencilValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorRenderCustomDepth(AActor* Actor, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LockOwnerForStencil(UObject* WorldContextObject, UPrimitiveComponent* Component, UObject*& Owner);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LockForStencil(UObject* WorldContextObject, UObject* LockOwner, UPrimitiveComponent* Component, int32 StencilValue, bool& bSuccess, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LockAllForStencil(UObject* WorldContextObject, UObject* LockOwner, AActor* Actor, int32 StencilValue, bool& bSuccess, bool bRenderCustomDepth);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsLockedForStencil(UObject* WorldContextObject, UPrimitiveComponent* Component, bool& bLocked);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AStencilManagerSingleton* GetStencilManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurrentStencilEffect(AActor* InTarget, FName& StencilEffect);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableStencilGroups(UObject* WorldContextObject, TArray<FName> Groups, bool bEnable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableStencilGroup(UObject* WorldContextObject, FName Group, bool bEnable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableStencil(UObject* WorldContextObject, bool bEnable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableStencilGroups(UObject* WorldContextObject, TArray<FName> Groups);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableStencilGroup(UObject* WorldContextObject, FName Group);
    
};

