#include "NavigationBlueprintLibrary.h"

class AActor;
class UActorComponent;
class UObject;

void UNavigationBlueprintLibrary::UpdateNavigationObstacles(AActor* TargetActor) {
}

bool UNavigationBlueprintLibrary::TraceWater(UObject* WorldContextObject, const FVector& TraceStart, const FVector& TraceEnd, float Radius, bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore, bool bIgnoreSelf, FHitResult& OutHit) {
    return false;
}

void UNavigationBlueprintLibrary::SwitchDynamicNavigation(AActor* TargetActor, bool bBlock) {
}

void UNavigationBlueprintLibrary::SetObjectStateInfoObstacleComponentActive(AActor* TargetActor, bool bActive) {
}

void UNavigationBlueprintLibrary::SetCanEverAffectNavigation(UActorComponent* ActorComponent, bool bCanAffectNavigation) {
}

void UNavigationBlueprintLibrary::RefreshObjectStateInfoActorObstacles(AActor* TargetActor, bool bForceDynamicSpawnedFlag) {
}

UNavigationBlueprintLibrary::UNavigationBlueprintLibrary() {
}

