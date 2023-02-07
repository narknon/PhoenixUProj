#include "FleshCache.h"

class AActor;
class UActorComponent;
class UFleshCache;
class UObject;

void UFleshCache::OnPreCacheFinished(AActor* InOwner) {
}

void UFleshCache::OnComponentActivated(UActorComponent* InComponent, bool InSuccess) {
}

void UFleshCache::HandleFastTravelFinished(const UObject* InCaller) {
}

void UFleshCache::HandleFastTravelBegun(const UObject* InCaller) {
}

UFleshCache* UFleshCache::Get() {
    return NULL;
}

UFleshCache::UFleshCache() {
}

