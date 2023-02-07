#include "MercunaNavigationComponent.h"

class AActor;
class AMercunaNavOctree;
class UObject;

void UMercunaNavigationComponent::TrackActor(AActor* Actor, float Distance, float Speed, bool SkipCheckNav) {
}

void UMercunaNavigationComponent::Stop() {
}

void UMercunaNavigationComponent::SetUsageFlags(FMercunaPawnUsageFlags& NewUsageFlags) {
}

void UMercunaNavigationComponent::SetNavOctree(AMercunaNavOctree* NewNavOctree) {
}

void UMercunaNavigationComponent::SetEnabled(bool bEnable) {
}

void UMercunaNavigationComponent::SetAvoidanceAgainst(AActor* Actor, bool Enable) {
}

void UMercunaNavigationComponent::ResumeNavigation() {
}

void UMercunaNavigationComponent::PauseNavigation() {
}

void UMercunaNavigationComponent::MoveToLocations(const TArray<FVector>& Destinations, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav) {
}

void UMercunaNavigationComponent::MoveToLocation(const FVector& Destination, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav) {
}

void UMercunaNavigationComponent::MoveToActor(AActor* Actor, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav) {
}

void UMercunaNavigationComponent::LookInDirection(FVector Direction, float MaxPitch) {
}

void UMercunaNavigationComponent::LookAt(AActor* Actor, float MaxPitch) {
}

void UMercunaNavigationComponent::IsReachable(FVector Point, bool& Success, UObject* WorldContextObject, FLatentActionInfo LatentInfo) {
}

void UMercunaNavigationComponent::GetPathInfo(bool& Valid, float& DistanceToEnd, FVector& NextPathPoint, bool& bIsFinalPoint) {
}

AMercunaNavOctree* UMercunaNavigationComponent::GetNavOctree() const {
    return NULL;
}

void UMercunaNavigationComponent::ConfigureMovement(bool bUsePathfinding, bool bUseDynamicAvoidance) {
}

void UMercunaNavigationComponent::Configure(const FMercunaNavigationConfiguration& NewConfiguration) {
}

void UMercunaNavigationComponent::ClearAvoidanceExclusions() {
}

void UMercunaNavigationComponent::CheckReachable(FVector Point, bool& Success, UObject* WorldContextObject, FLatentActionInfo LatentInfo) {
}

void UMercunaNavigationComponent::CancelMovement() {
}

void UMercunaNavigationComponent::CancelLookAt() {
}

void UMercunaNavigationComponent::AddDestinationLocation(FVector NextDestination) {
}

UMercunaNavigationComponent::UMercunaNavigationComponent() {
    this->NavOctree = NULL;
    this->Pathfinding = true;
    this->DynamicAvoidance = true;
}

