#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorTracker.h"
#include "BoneTracker.h"
#include "LocatorTracker.h"
#include "RefPoseTracker.h"
#include "SocketTracker.h"
#include "LocatorTrackerLibrary.generated.h"

class AActor;
class USceneComponent;

UCLASS(Blueprintable)
class SKINFX_API ULocatorTrackerLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULocatorTrackerLibrary();
    UFUNCTION(BlueprintCallable)
    static void MakeSocketTracker(AActor* Actor, FName SocketName, FSocketTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable)
    static void MakeRefPoseTracker(AActor* Actor, FName BoneName, FRefPoseTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable)
    static void MakeComponentTracker(USceneComponent* Component, FLocatorTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBoneTracker(AActor* Actor, FName BoneName, FBoneTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable)
    static void MakeActorTracker(AActor* Actor, FActorTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable)
    static void GetRefPoseTransform(AActor* Actor, FName BoneName, FTransform& Transform, bool& bValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocatorTrackerVelocity(const FLocatorTracker& Tracker, FVector& Velocity, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocatorTrackerValid(const FLocatorTracker& Tracker, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocatorTrackerTransform(const FLocatorTracker& Tracker, FTransform& Transform, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocatorTrackerSceneComponent(const FLocatorTracker& Tracker, USceneComponent*& SceneComponent, bool& bTrackerValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocatorTrackerActor(const FLocatorTracker& Tracker, AActor*& Actor, bool& bTrackerValid);
    
};

