#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MotionTableEvent.h"
#include "MotionTableState.h"
#include "MotionTable.generated.h"

UCLASS(Blueprintable)
class AMBULATORY_API UMotionTable : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMotionTableState> StateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMotionTableEvent> EventData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FName> AliasStateNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FString> AliasesWithVariations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FName> AnimationStateNameMap;
    
public:
    UMotionTable();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStateTransition(FName InStartState, FName InEndState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEventTransition(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetVariationStateNameFromAnimation(const FString& InAnimationName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTravelDistanceToState(float InTimeToReachState, FName InEndState, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTravelDistanceToEvent(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToReachEventBefore(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToReachEvent(FName InEventName, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToReachEndStateBefore(float InTimeToReachEndState, FName InEndState, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToReachEndState(FName InEndState, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStateTransitionTravelDistance(FName InStartState, FName InEndState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStateTransitionDuration(FName InStartState, FName InEndState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetStateNameFromAlias(const FString& InAliasedStateName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetStateContainingEvent(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNearestTimeToReachEvent(float InTimeToReachEvent, FName InEventName, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNearestTimeToReachEndState(float InTimeToReachEndState, FName InEndState, FName InStartState, float InCycleTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEventTransitionTravelDistance(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEventFollowThroughTravelDistance(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEventFollowThroughDuration(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEventCycleTime(FName InEventName, FName InStartState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AliasHasVariations(const FString& InAliasedStateName) const;
    
};

