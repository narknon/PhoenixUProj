#include "InsideOutside.h"

class AActor;
class UObject;

bool UInsideOutside::PositionOutside(UObject* WorldContextObject, FVector Position, bool bExact) {
    return false;
}

bool UInsideOutside::PositionInside(UObject* WorldContextObject, FVector Position, bool bExact) {
    return false;
}

bool UInsideOutside::ActorOutsideExactCached(AActor* Actor) {
    return false;
}

bool UInsideOutside::ActorOutsideCoarseCached(AActor* Actor) {
    return false;
}

bool UInsideOutside::ActorOutsideCached(AActor* Actor) {
    return false;
}

bool UInsideOutside::ActorInsideExactCached(AActor* Actor) {
    return false;
}

bool UInsideOutside::ActorInsideCoarseCached(AActor* Actor) {
    return false;
}

bool UInsideOutside::ActorInsideCached(AActor* Actor) {
    return false;
}

UInsideOutside::UInsideOutside() {
}

