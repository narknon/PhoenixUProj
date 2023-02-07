#include "AncientGateManager.h"

class AActor;
class UActorComponent;
class UAncientGateManager;

void UAncientGateManager::SetAncientGateCollision(AActor* Actor, TEnumAsByte<ECollisionResponse> CollisionResponse) {
}

void UAncientGateManager::GetAncientGatePrimitives(AActor* Actor, TArray<UActorComponent*>& Primitives) {
}

UAncientGateManager* UAncientGateManager::Get() {
    return NULL;
}

UAncientGateManager::UAncientGateManager() {
}

