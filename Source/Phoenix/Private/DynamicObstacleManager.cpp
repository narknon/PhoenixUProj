#include "DynamicObstacleManager.h"

class AActor;
class UDynamicObstacleManager;
class UObject;
class UWorld;

void UDynamicObstacleManager::OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

void UDynamicObstacleManager::OnActorDestroyed(AActor* DestroyedActor) {
}

UDynamicObstacleManager* UDynamicObstacleManager::GetDynamicObstacleManager(UObject* WorldContext) {
    return NULL;
}

UDynamicObstacleManager* UDynamicObstacleManager::Get(UWorld* NewWorld) {
    return NULL;
}

UDynamicObstacleManager::UDynamicObstacleManager() {
}

