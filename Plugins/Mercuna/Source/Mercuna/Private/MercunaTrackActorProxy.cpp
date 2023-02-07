#include "MercunaTrackActorProxy.h"

class AActor;
class APawn;
class UMercunaTrackActorProxy;
class UObject;

void UMercunaTrackActorProxy::OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result) {
}

UMercunaTrackActorProxy* UMercunaTrackActorProxy::MercunaTrackActor(UObject* WorldContextObject, APawn* Pawn, AActor* Actor, float Distance, float Speed) {
    return NULL;
}

UMercunaTrackActorProxy::UMercunaTrackActorProxy() {
}

