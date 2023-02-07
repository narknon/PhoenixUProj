#include "LODActorRotationManager.h"

class AActor;

TArray<AActor*> ALODActorRotationManager::FilterValidActorRef(TArray<TSoftObjectPtr<AActor>> ActorRefList) {
    return TArray<AActor*>();
}

void ALODActorRotationManager::CheckLOD0ActorRefValid(TSoftObjectPtr<AActor> ActorRef, bool& bTrue) {
}

void ALODActorRotationManager::CheckAnyActorRefValid(TArray<TSoftObjectPtr<AActor>> ActorRefList, bool& bTrue) {
}

ALODActorRotationManager::ALODActorRotationManager() {
}

