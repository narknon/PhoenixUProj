#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterOverlapThrottlerSettings.h"
#include "MasterOverlapThrottlerTracker.h"
#include "MasterOverlapThrottlerSingleton.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable, Transient)
class MASTEROVERLAPTHROTTLER_API AMasterOverlapThrottlerSingleton : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPrimitiveComponent>, FMasterOverlapThrottlerTracker> ThrottlePrimitiveComponents;
    
public:
    AMasterOverlapThrottlerSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void RemoveManagedPrimitiveComponent(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsPrimitiveComponentThrottled(UPrimitiveComponent* Component, bool& bIsThrottled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsManagedPrimitiveComponent(UPrimitiveComponent* Component, bool& bIsManaged);
    
    UFUNCTION(BlueprintCallable)
    static void EnablePrimitiveComponentThrottling(UPrimitiveComponent* Component, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void DisablePrimitiveComponentThrottling(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static void AddManagedPrimitiveComponent(UPrimitiveComponent* Component, const FMasterOverlapThrottlerSettings& Settings);
    
};

