#include "LocatorTrackerLibrary.h"

class AActor;
class USceneComponent;

void ULocatorTrackerLibrary::MakeSocketTracker(AActor* Actor, FName SocketName, FSocketTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::MakeRefPoseTracker(AActor* Actor, FName BoneName, FRefPoseTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::MakeComponentTracker(USceneComponent* Component, FLocatorTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::MakeBoneTracker(AActor* Actor, FName BoneName, FBoneTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::MakeActorTracker(AActor* Actor, FActorTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::GetRefPoseTransform(AActor* Actor, FName BoneName, FTransform& Transform, bool& bValid) {
}

void ULocatorTrackerLibrary::GetLocatorTrackerVelocity(const FLocatorTracker& Tracker, FVector& Velocity, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::GetLocatorTrackerValid(const FLocatorTracker& Tracker, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::GetLocatorTrackerTransform(const FLocatorTracker& Tracker, FTransform& Transform, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::GetLocatorTrackerSceneComponent(const FLocatorTracker& Tracker, USceneComponent*& SceneComponent, bool& bTrackerValid) {
}

void ULocatorTrackerLibrary::GetLocatorTrackerActor(const FLocatorTracker& Tracker, AActor*& Actor, bool& bTrackerValid) {
}

ULocatorTrackerLibrary::ULocatorTrackerLibrary() {
}

