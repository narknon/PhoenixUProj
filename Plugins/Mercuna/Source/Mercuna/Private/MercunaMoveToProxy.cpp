#include "MercunaMoveToProxy.h"

class AActor;
class APawn;
class UMercunaMoveToProxy;
class UObject;

void UMercunaMoveToProxy::OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result) {
}

UMercunaMoveToProxy* UMercunaMoveToProxy::MercunaMoveToLocations(UObject* WorldContextObject, APawn*& Pawn, const TArray<FVector>& Destinations, float EndDistance, float Speed, bool UsePartialPath) {
    return NULL;
}

UMercunaMoveToProxy* UMercunaMoveToProxy::MercunaMoveToLocation(UObject* WorldContextObject, APawn* Pawn, const FVector& Destination, float EndDistance, float Speed, bool UsePartialPath) {
    return NULL;
}

UMercunaMoveToProxy* UMercunaMoveToProxy::MercunaMoveToActor(UObject* WorldContextObject, APawn* Pawn, AActor* Actor, float EndDistance, float Speed, bool UsePartialPath) {
    return NULL;
}

UMercunaMoveToProxy::UMercunaMoveToProxy() {
}

