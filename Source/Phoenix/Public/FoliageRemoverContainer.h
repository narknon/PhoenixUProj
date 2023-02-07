#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FoliageRemoverContainer.generated.h"

class AInstancedFoliageActor;
class ALandscapeProxy;
class UFoliageRemoverBoundsComponent;
class UWorld;

UCLASS(Blueprintable)
class UFoliageRemoverContainer : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFoliageRemoverBoundsComponent*> ActiveFoliageRemoverBoundsComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFoliageRemoverBoundsComponent*> PendingRegisterComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFoliageRemoverBoundsComponent*> PendingUnregisterComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFoliageRemoverBoundsComponent*> RetryRemoveGrassComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFoliageRemoverBoundsComponent*> RetryRemoveFoliageComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* CachedWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AInstancedFoliageActor*> CachedInstancedFoliageActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ALandscapeProxy*> CachedLandscapeProxies;
    
public:
    UFoliageRemoverContainer();
    UFUNCTION(BlueprintCallable)
    void UnregisterFoliageRemoverBoundsComponent(UFoliageRemoverBoundsComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void RegisterFoliageRemoverBoundsComponent(UFoliageRemoverBoundsComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnAnyLevelLoaded();
    
};

