#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "OnWorldEventLevelLoadedDelegate.h"
#include "WorldEventTimeSpan.h"
#include "WorldEventLocationActor.generated.h"

class UWorldEventCondition;
class UWorldEventSocketComponent;

UCLASS(Abstract, Blueprintable)
class PHOENIX_API AWorldEventLocationActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWorldEventLevelLoaded OnLevelLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldEventCondition*> LoadedConditions;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer locationDescriptors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PercentChanceOfBeingSelected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StreamInDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StreamOutDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorldEventCondition>> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDefaultCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldEventTimeSpan CooldownOverride;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnEventWithLevel;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMissionCritical;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GuidString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDrawStreamingVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseForcedWorldEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ForcedWorldEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseForcedWorldEventSubset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ForcedWorldEventSubset;
    
private:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UWorldEventSocketComponent>> WorldEventSockets;
    
public:
    AWorldEventLocationActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool UseForcedWorldEventSubset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool UseForcedWorldEventName() const;
    
    UFUNCTION(BlueprintCallable)
    void StreamingHandle();
    
    UFUNCTION(BlueprintCallable)
    void SetLocatorName(const FName& Name);
    
    UFUNCTION(BlueprintCallable)
    UWorldEventSocketComponent* RequestSocket(const FGameplayTagContainer& SocketDescriptors);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseAllSockets();
    
    UFUNCTION(BlueprintCallable)
    void OnEventNaturalEnd();
    
    UFUNCTION(BlueprintCallable)
    void MarkEventAsCompleted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPercentChanceOfBeingSelected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfSockets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetLocatorName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetLocationDescriptors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetForcedWorldEventSubset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetForcedWorldEventName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSoftObjectPtr<UWorldEventCondition>> GetConditions() const;
    
};

