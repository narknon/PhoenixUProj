#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "MasterTickThrottlerSettings.h"
#include "MasterTickThrottlerTracker.h"
#include "MasterTickThrottlerSingleton.generated.h"

class UActorComponent;

UCLASS(Blueprintable, Transient)
class MASTERTICKTHROTTLER_API AMasterTickThrottlerSingleton : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FMasterTickThrottlerTracker> ThrottleActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UActorComponent>, FMasterTickThrottlerTracker> ThrottleComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLastEyeValid;
    
public:
    AMasterTickThrottlerSingleton();
    UFUNCTION(BlueprintCallable)
    static void RemoveManagedComponent(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveManagedActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsManagedComponent(UActorComponent* Component, bool& bIsManaged);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsManagedActor(AActor* Actor, bool& bIsManaged);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsComponentThrottled(UActorComponent* Component, bool& bIsThrottled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsActorThrottled(AActor* Actor, bool& bIsThrottled);
    
    UFUNCTION(BlueprintCallable)
    static void EnableComponentThrottling(UActorComponent* Component, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void EnableActorThrottling(AActor* Actor, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void DisableComponentThrottling(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static void DisableActorThrottling(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void AddManagedComponent(UActorComponent* Component, const FMasterTickThrottlerSettings& Settings);
    
    UFUNCTION(BlueprintCallable)
    static void AddManagedActor(AActor* Actor, const FMasterTickThrottlerSettings& Settings);
    
};

